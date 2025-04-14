#include <winsock2.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INT_SIZE sizeof(unsigned long)
#define REQUEST_SIZE 35
#define PORT 7788
#define BUFFER_SIZE 1024
#define STOP_BYTE 0xFF
#define VIDEO_PATH "./"
#define END_REQUEST "END_REQUEST"
#define VIDEO_LEN 60 // 视频总时长为60s

// 定义一个获取文件大小的函数，参数是一个文件指针
long get_file_size(FILE *fp)
{
    long file_size = -1;
    fpos_t cur_pos;
    fgetpos(fp, &cur_pos);
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fsetpos(fp, &cur_pos);
    return file_size;
}

int main()
{
    /***初始化阶段***/
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    int server_fd, new_socket;
    struct sockaddr_in server_address;
    int opt = 1;
    int addrlen = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};

    // 创建套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    else
        printf("Create Server Socket Success.\n");

    // 设置套接字选项
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // 绑定套接字
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    else
        printf("Server Bind Port Success. \n");

    // 监听套接字
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    else
        printf("Server Listening......\n");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&server_address, &addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    else
        printf("Server Accept Success. \n");

    while (1)
    {
        // 接收客户端下载请求
        int bytes_recv = 0;
        char req[REQUEST_SIZE] = "";
        bytes_recv = recv(new_socket, req, REQUEST_SIZE, 0);
        if (bytes_recv <= 0)
        {
            printf("Client disconnected or error in recv\n");
            break;
        }
        printf("Received request: %s\n", req);
        
        // 检查请求是否要求结束连接
        if (strcmp(req, END_REQUEST) == 0)
        {
            printf("Received end request, closing connection.\n");
            break;
        }
        
        // 接收停止字节
        unsigned char r_stop_byte;
        if (recv(new_socket, &r_stop_byte, 1, 0) != 1 || r_stop_byte != STOP_BYTE)
        {
            printf("ERROR in receiving stop byte 0x%02X\n", r_stop_byte);
            continue;
        }

        // 构建文件路径并打开文件
        char file_path[100] = VIDEO_PATH;
        strcat(file_path, req);
        printf("Opening file: %s\n", file_path);
        
        FILE *fp = fopen(file_path, "rb");
        if (fp == NULL)
        {
            perror("File open failed");
            // 发送错误信息给客户端
            unsigned long error_size = 0;
            send(new_socket, (char *)&error_size, INT_SIZE, 0);
            continue;
        }

        // 获取并发送文件大小
        unsigned long file_size = (unsigned long)get_file_size(fp);
        printf("File size: %lu bytes\n", file_size);

        unsigned long file_size_buf = htonl(file_size);
        int bytes_sent = send(new_socket, (char *)&file_size_buf, INT_SIZE, 0);
        if (bytes_sent < 0)
        {
            printf("ERROR sending file size\n");
            fclose(fp);
            continue;
        }

        // 发送文件内容
        int send_count = 0;
        char video_buffer[BUFFER_SIZE] = {0};
        
        while (send_count < file_size)
        {
            size_t bytes_read = fread(video_buffer, 1, BUFFER_SIZE, fp);
            if (bytes_read == 0)
            {
                if (feof(fp))
                {
                    printf("Reached end of file\n");
                    break;
                }
                else if (ferror(fp))
                {
                    perror("Error reading file");
                    break;
                }
            }
            
            bytes_sent = send(new_socket, video_buffer, bytes_read, 0);
            if (bytes_sent < 0)
            {
                perror("Error sending data");
                break;
            }
            
            send_count += bytes_sent;
            printf("\rSent: %d/%lu bytes (%.2f%%)", 
                   send_count, file_size, 
                   (float)send_count / file_size * 100);
            fflush(stdout);
        }
        printf("\nFile transfer completed!\n");

        // 发送文件结束符
        unsigned char s_stop_byte = STOP_BYTE;
        bytes_sent = send(new_socket, &s_stop_byte, 1, 0);
        if (bytes_sent < 0)
        {
            printf("ERROR sending stop byte\n");
        }
        
        // 等待客户端确认
        if (recv(new_socket, &r_stop_byte, 1, 0) == 1 && r_stop_byte == STOP_BYTE)
        {
            printf("Client acknowledged receipt of file\n");
        }

        // 关闭文件
        fclose(fp);
        printf("File closed\n");
        
    }

    /***结束阶段***/
    closesocket(server_fd);
    closesocket(new_socket);
    WSACleanup();
    printf("Server shutdown complete\n");

    // Keep command window open until user chooses to exit
    printf("\nPress Enter key to exit...");
    getchar();
    
    return 0;
}
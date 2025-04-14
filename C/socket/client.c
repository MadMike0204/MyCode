#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>

#define DOWNLOAD_PATH "./download/"

#define INT_SIZE sizeof(int)
#define REQUEST_SIZE 35
#define PORT 7788
#define BUFFER_SIZE 1024
#define STOP_BYTE 0xFF
#define VIDEO_LEN 60 // 视频总时长为60s

int main()
{
    /***初始化阶段***/
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // 创建下载目录
    system("mkdir download 2> nul");  // On Windows, 2> nul suppresses errors if directory exists

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        return -1;
    }
    else
        printf("Client Create Socket Success. \n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection Failed");
        return -1;
    }
    else
        printf("Client Connect Server Success. \n");

    /*****************************************************************/
    /********** 任务1： 如何向server循环请求连续的视频文件？**********/
    /*****************************************************************/

    // 发送下载请求
    int bytes_sent = 0;
    unsigned char s_stop_byte = 0xFF;

    // 视频文件名
    char req[REQUEST_SIZE] = "ocean-480p-2500k.mp4";
    bytes_sent = send(sock, req, REQUEST_SIZE, 0);
    if (bytes_sent < 0)
        printf("ERROR in send\n");
    bytes_sent = send(sock, &s_stop_byte, sizeof(s_stop_byte), 0);
    if (bytes_sent < 0)
        printf("ERROR in send\n");
    printf("send req: %s\n", req);

    // 接收文件的大小
    int file_size;
    unsigned long file_size_buf;
    int bytes_recv = 0;
    bytes_recv = recv(sock, (char *)&file_size_buf, INT_SIZE, 0);
    file_size = ntohl(file_size_buf);
    printf("file_size %d \n", file_size);

    // 准备文件路径
    char file_path[40] = DOWNLOAD_PATH;
    strcat(file_path, req);
    printf("Saving to: %s\n", file_path);
    
    // 打开文件准备写入
    FILE *fp = fopen(file_path, "wb");
    if (fp == NULL)
    {
        perror("Failed to open file for writing");
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // 接收视频片段
    int recv_count = 0;
    char buffer_recv[BUFFER_SIZE] = {0};

    while (recv_count < file_size)
    {
        int bytes_received = recv(sock, buffer_recv, BUFFER_SIZE, 0);
        if (bytes_received <= 0)
        {
            perror("Error receiving data");
            break;
        }
        
        // 写入文件
        size_t bytes_written = fwrite(buffer_recv, 1, bytes_received, fp);
        if (bytes_written < bytes_received)
        {
            perror("Failed to write all data to file");
            break;
        }
        
        recv_count += bytes_received;
        printf("\rReceived: %d/%d bytes (%.2f%%)", 
               recv_count, file_size, 
               (float)recv_count / file_size * 100);
        fflush(stdout);
    }
    printf("\nReceive completed!\n");

    // 关闭文件
    fclose(fp);

    // 检查文件结束符
    unsigned char r_stop_byte;
    if (recv(sock, &r_stop_byte, 1, 0) != 1 || r_stop_byte != STOP_BYTE)
    {
        printf("ERROR in receiving stop byte 0x%02X \n", r_stop_byte);
    }
    else
    {
        printf("File transfer completed successfully.\n");
    }

    // 向服务器发送确认信息（可选）
    s_stop_byte = 0xFF;
    send(sock, &s_stop_byte, sizeof(s_stop_byte), 0);

    /***结束阶段***/
    closesocket(sock);
    WSACleanup();
    printf("Connection closed.\n");

    // Keep command window open until user chooses to exit
    printf("\nPress Enter key to exit...");
    getchar();
    
    return 0;
}
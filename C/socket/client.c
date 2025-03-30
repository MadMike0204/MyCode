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
    /******************************************************************/
    /***************** 任务2：如何按顺序选择视频文件？*****************/
    /******************************************************************/

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

    // 接收视频片段
    char *video_segement = malloc(file_size);
    if (video_segement == NULL)
    {
        perror("malloc failed");
        // 处理内存分配失败的情况，可能需要退出程序
        return -1;
    }
    int recv_count = 0;

    char* video_buffer = malloc(BUFFER_SIZE);
    FILE* file_ptr = fopen(video_segement,"wb");

    while (recv_count < file_size)
    {
        int byte_received = recv(sock,video_buffer,BUFFER_SIZE,0);
        if(byte_received < 0){
            perror("Error occurred.");
        }
        size_t bytes_written = fwrite(video_buffer,1,byte_received,file_ptr);
        recv_count += byte_received;
        /************************************************************************/
        /***************** 任务3 ： 如何使用buffer接收视频文件？*****************/
        /************************************************************************/
    }

    unsigned char r_stop_byte;
    if (recv(sock, &r_stop_byte, 1, 0) != 1 || r_stop_byte != STOP_BYTE)
        printf("ERROR in receiving stop byte 0x%02X \n", r_stop_byte); // 检查文件结束符
    r_stop_byte = 'e';                                                 // 重置

    // unsigned char s_stop_byte = 0xFF;
    // send(sock,s_stop_byte,sizeof(STOP_BYTE),0);


    // 写入文件
    char file_path[40] = DOWNLOAD_PATH;
    strcat(file_path, req);
    printf("file_path %s \n", file_path);
    FILE *fp = fopen(file_path, "wb"); // 以二进制模式打开文件，并返回文件指针
    if (fp == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fwrite(video_segement, 1, file_size, fp);

    /***数据接收完成阶段***/

    // 释放内存
    free(video_segement);
    video_segement = NULL;

    /*************************************************************************************/
    /*********任务2（扩展）：如何在视频流传输完成后，通知server结束视频传输？*************/
    /*************************************************************************************/

    /***结束阶段***/
    closesocket(sock);
    WSACleanup();

    return 0;
}
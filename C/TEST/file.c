#include<stdio.h>
int main(){

    FILE* fp;
    
    fp = fopen("C:/Users/Admin/Desktop/hello.txt","w");
    if(fp == NULL)
    {
        return -1;
    }
    printf("jostar");
    fprintf(fp,"FUCK U NVIDIA\n");

    fclose(fp);



    return 0;
}
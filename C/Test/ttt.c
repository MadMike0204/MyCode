#include <stdio.h>


typedef struct The_Users
{
    char id[10];
    char passward[10];
    int age;
    char gender[10];
    char phonenumber[10];
    char nationality[10];
    char prefer[10];
}Users;
typedef struct The_Music
{
    char name[20];
    int year;
    char singer[10];
    char language[5];
    char time[5];
    int style1;
    int style2;
    int style3;
}Music;

void Read_Music(FILE *fp2,Music song[50])
{
    //fp2 = fopen("Musics.txt", "r");
    int i=0;
    while(!feof(fp2))
    {
        fscanf(fp2,"%s %d %s %s %s %d %d %d",song[i].name,&song[i].year,song[i].singer,song[i].language,song[i].time,&song[i].style1,&song[i].style2,&song[i].style3);
        i++;
    }
    fclose(fp2);
} 

void Show_Music()
{
    Music song[50];

    for(int i=0;i<25;i++)
    {
        song[i].name[0] = 'K';
    }
    printf("我草");
    int i=0;
    while(song[i].name[0]!='\0')
    {
        printf("%d. %s\n",i+1,song[i].name);
        i++;
    }
}

int main()
{
    while(1)
        printf("神魔问题");


    return 0;
}
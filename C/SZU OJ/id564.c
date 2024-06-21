#include<stdio.h>
int main(){

    int grades[999];
    const int* To_grades;
    To_grades = NULL;
    int t,n,i,aim1,aim2,aim3;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&grades[i]);
        }
        To_grades = &grades[n/2];
        scanf("%d",&aim1);
        printf("%d %d\n",*(To_grades - 1),*(To_grades + 1));
        
        To_grades -= (n / 2) - (aim1 - 1);
        printf("%d\n",*To_grades);
        To_grades = &grades[n/2];
        t--;
    }

    return 0;
}
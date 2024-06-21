#include <stdio.h>
//鞍点
int main()
{
  int a[10][10], c[10], d[10];
  int m, n, T,i, j;
  scanf("%d",&T);
  while(T>0)
    {
        int k = 0;
        scanf("%d%d", &m, &n);
        for (i = 0; i < m; i++)
            {
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
            }
        for (i = 0; i < m; i++)
            {
            c[i] = a[i][0];
            for (j = 0; j < n; j++)
                {
                if (c[i] < a[i][j])
                    c[i] = a[i][j];
                }
            }
        for (j = 0; j < n; j++)
            {
            d[j] = a[0][j];
            for (i = 0; i < m; i++)
                {
                if (d[j] > a[i][j])
                    d[j] = a[i][j];
                }
            }
        for (i = 0; i < m; i++)
            {
            for (j = 0; j < n; j++)
                {
                if (a[i][j] == c[i] && a[i][j] == d[j])
                    {
                    printf("%d %d %d\n",a[i][j],i+1,j+1);
                    k = 1;
                    }
                }
            }
        if (k == 0)
            printf("null\n");
    }
  return 0;
}

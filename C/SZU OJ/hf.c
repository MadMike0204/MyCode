#include<stdio.h>
int main() {
    int N, i, j, k, z, m, n, x, y, p, l, t, sum1, sum2, sum3, sum4, sum;
    char str[100];
    scanf("%d", &N);
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int d[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    while (1) {
        scanf("%s", &str);
		int kk = 1;
        if (str == "TRANSLATE") {
            for (m = 0; m < N; m++) {
                for (n = 0; n < N - 1; n++) {
                    b[m][n] = a[n][m];
                    printf("%d ", b[m][n]);
                }
                printf("%d\n", b[m][n]);
            }
        } else if (str == "ADD") {
            for (k = 0; k < N; k++) {
                for (z = 0; z < N; z++) {
                    scanf("%d", &c[k][z]);
                }
            }
            for (m = 0; m < N; m++) {
                for (n = 0; n < N - 1; n++) {
                    b[m][n] = a[m][n] + c[m][n];
                    printf("%d ", b[m][n]);
                }
                printf("%d\n", b[m][n]);
            }
        } else if (str == "MULTIPLY") {
            for (x = 0; x < N; x++) {
                for (y = 0; y < N; y++) {
                    scanf("%d", &d[x][y]);
                }
            }
            sum1 = 0;
            sum2 = 0;
            for (m = 0; m < N; m++) {
                for (n = 0; n < N - 1; n++) {
                    sum1 += a[m][n];
                    sum2 += d[n][m];
                }
            }
            for (p = 0; p < N; p++) {
                for (l = 0; l < N - 1; l++) {
                    b[p][l] = b[sum1][sum2];
                    printf("%d ", b[p][l]);
                }
                printf("%d\n", b[p][l]);
            }
        } else if (str == "SUM") {
            sum3 = 0;
            sum4 = 0;
            for (t = 0; t < N; t++) {
                sum3 += a[t][t];
                sum4 += a[t][N - 1 - t];
            }
            sum = sum3 + sum4;
            printf("%d %d\n", sum);
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                a[i][j] = b[i][j];
            }
        }

        if (str == "BREAK")
            break;
    }
    return 0;
}

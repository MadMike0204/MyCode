#include<stdio.h>
int main()
{
	int T;
	int x1, x2, y1, y2, x3, x4, y3, y4;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
		if ((x1 <= x3 && x3 <= x2 && y1 <= y3 && y3 <= y2) || (x1 <= x4 && x4 <= x2 && y1 <= y4 && y4 <= y2)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

	}

	return 0;
}
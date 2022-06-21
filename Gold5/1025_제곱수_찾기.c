#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int matrix[9][9];

int isSquare(int n) {
	int root = (int)sqrt(n);
	return (root*root) == n;
}


int main() {

	int N, M, i, j, tmp, ans = -1, num, a, b, I, J;

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &tmp);
		for (j = M-1; j >= 0; j--) {
			matrix[i][j] = tmp%10;
			tmp /= 10;
		}
	}

	for (a = 0; a <= N; a++) {					//행 첫번째 항
		for (b = 0; b <= M; b++) {				//열 첫번째 항
			for (i = -N ; a + i <= N; i++) {		//행 공차
				for (j = -M; b + j <= M; j++) {	//열 공차
					if (i || j) {
						I = a; J = b;
						num = 0;
						while (I < N && J < M && I >= 0 && J >= 0) {

							num *= 10;
							num += matrix[I][J];

							if (isSquare(num))
								ans = (ans > num) ? ans : num;

							I += i; J += j;
						}
					}
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}

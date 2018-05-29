#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int main()
{
	int n;
	scanf("%d", &n);
	int i, j;
	int M[n + 1][n + 1];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", M[i][j]);
	int **S;
	S = (int**)calloc(sizeof(int*), n);
	for(i = 1; i <= n; i++)
		S[i] = (int*)calloc(sizeof(int), n);
		S[1][1] = M[1][1];
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			S[i][j] = max(max(S[i - 1][j], S[i][j - 1]), S[i - 1][j - 1]) + M[i][j];
	printf("%d", S[n][n]);
	return 0;

}
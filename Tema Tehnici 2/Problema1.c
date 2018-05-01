#include <stdio.h>
#include <stdlib.h>

int *citire(int *t, int *n)
{
	FILE* in = fopen("problema1.in", "r");
	t = (int*)malloc(sizeof(int) * *n);
	fscanf(in, "%d", n);
	int i = 0;
	for(; i < *n; fscanf(in, "%d", &t[i++]));
	fclose(in);
	return t;
}

int cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int *Rezolvare(int *t, int n, float *medie)
{
	qsort(t, n, sizeof(int), cmp);
	int s = 0, i = 0;
	for(; i < n;  i++)
		{
		s += t[i];
		*medie += s;
		}
	
	*medie /= n;
	return t;
}

void Afisare(int *t, int n, float medie)
{
	FILE* out = fopen("problema1.out", "w");
	int i = 0;
	for(; i < n; fprintf(out, "%d ", t[i++]));
	fprintf(out, "\n%f", medie);
	fclose(out);
}

int main()
{
	int *t, n, i = 0;
	float medie = 0;
	t = citire(t, &n);
	Rezolvare(t, n, &medie);
	Afisare(t, n, medie);
	free(t);
	return 0;
}
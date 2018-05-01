#include <stdio.h>
#include <stdlib.h>

int *citire(int *lungimi, int *n)
{
	FILE *fin = fopen("problema2.in", "r");			///fin ca pielea de delfin - Olimpiada 2016
	fscanf(fin, "%d", n);
	lungimi = (int*)malloc(sizeof(int) * *n);
	int i = 0;
	for(; i < *n; fscanf(fin, "%d", &lungimi[i++]));
	fclose(fin);
	return lungimi;
}

int cmp(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int Rezolvare(int *lungimi, int n)
{
	
	qsort(lungimi, n, sizeof(int), cmp);

	int i = 1, cost = 0, costPartial = lungimi[0];
	for(; i < n; costPartial += lungimi[i++], cost += costPartial);
	return cost;
}

void Afisare(int cost)
{
	FILE *out = fopen("problema2.out", "w");
	fprintf(out, "%d\n", cost);
	fclose(out);
}

int main()
{
	int *lungimi, n, cost;
	lungimi = citire(lungimi, &n);
	Afisare(Rezolvare(lungimi, n));
	free(lungimi);
	return 0;
}
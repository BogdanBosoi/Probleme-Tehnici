#include <stdio.h>
#include <stdlib.h>

void citire(int *nr_elem, int **elemVect, int *deCautat)
{
	FILE *fin = fopen("primprob.in", "r");
	fscanf(fin, "%d", nr_elem);
	*elemVect = (int*)malloc(sizeof(int) * *nr_elem);
	int contor = 0;
	for(; contor < *nr_elem; fscanf(fin, "%d", *elemVect[contor++]));
		fscanf(fin, "%d", *elemVect[contor]);
	fscanf(fin, "%d", deCautat);
	printf("%d\n", *deCautat);
	fclose(fin);
}
int counter = 0;
void cauta_binar(int *elemVect, int st, int dr, int elem)
{
	if(dr > st)
	{

		int mij = st + (dr - st)/2;
		if(elemVect[mij] == elem)
			{

				int i = mij;
				for(i = mij; i <= dr && elemVect[i] != elem; i++)
					if(elemVect[i] == elem)
						counter++;
				for(i = mij - 1; i >= st && elemVect[i] != elem; i--)
					if(elemVect[i] == elem)
						counter++;
					printf("%d", counter);
					return ;
			}
		else if(elemVect[mij] < elem)
			return cauta_binar(elemVect, mij, dr, elem);
		else
			return cauta_binar(elemVect, st, mij - 1, elem);
	}
}

int main()
{
	int *elemVect, nr_elem, deCautat;
	citire(&nr_elem, &elemVect, &deCautat);
	cauta_binar(elemVect, 0, nr_elem - 1, deCautat);
	return 0;
}
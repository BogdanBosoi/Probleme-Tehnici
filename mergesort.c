#include <stdio.h>
#include <stdlib.h>


void Merge(int *v, int st, int dr, int mij)
{
    int n = dr - st + 1;
    int aux[n];
    int i = st, j = mij + 1, k = 0;

    while(i < mij + 1 && j < dr)
        aux[k++] = (v[i] >= v[j]) ? v[i++] : v[j++];

    for(; i < mij + 1; aux[k++] = v[i++]);

    for(; j < dr; aux[k++] = v[j++]);

    for(i = st, k = 0; i < dr; i++)
        v[i] = aux[k++];

}

void merge_sort(int *v, int st, int dr)
{
    if(st < dr)
    {
        int m = st + (dr - st)/2;


        merge_sort(v, st, m);
        merge_sort(v, m + 1, dr);

        Merge(v, st, m, dr);
    }
}

int *Citire(int *Vector, int *numarElem)
{
    FILE *fin = fopen("binary.in", "r");
    fscanf(fin, "%d", numarElem);

    Vector = (int*)malloc(sizeof(int) * *numarElem);

    short contor;
    for(contor = 0; contor < *numarElem; fscanf(fin, "%d", &Vector[contor++]));

    fclose(fin);
    return Vector;
}


int main()
{
    int *v, n;
    v = Citire(v, &n);
    merge_sort(v, 0, n - 1);
    int contor = 0;
    for(; contor < n; printf("%d ", v[contor++]));
    return 0;
}

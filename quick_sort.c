#include <stdio.h>
#include <stdlib.h>

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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partitionare(int *Vector, int st, int dr)
{
    int i = st, j = dr;
    int tmp;

    int pivot = Vector[(st + dr) / 2];

    while(i <= j)
    {
        while(Vector[i] < pivot)
            i++;
        while(Vector[j] > pivot)
            j--;

        if(i <= j)
        {
            swap(&Vector[i], &Vector[j]);
            i++, j--;
        }
    }
    return i;
}

void quick_sort(int *Vector, int st, int dr)
{
    int elem = partitionare(Vector, st, dr);
    if(st < elem - 1)
        quick_sort(Vector, st, elem - 1);
    if(elem < dr)
        quick_sort(Vector, elem, dr);
}

int main()
{
    int *Vector, numarElem;
    Vector = Citire(Vector, &numarElem);
    quick_sort(Vector, 0, numarElem - 1);
    short contor = 0;
    for(; contor < numarElem; printf("%d ", Vector[contor++]));
    return 0;
}

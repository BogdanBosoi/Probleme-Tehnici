#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionare(int *Vector, int st, int dr)
{
    int i = st, j = dr;
    int tmp;

    int pivot = Vector[(dr + st)/2];

    while(i <= j)
    {
        while(Vector[i] < pivot) i++;
        while(Vector[j] > pivot) j--;
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

void printVector(int *A, int n)
{
    int i;
    for(i = 0; i < n; printf("%d ", A[i++]));
    printf("\n");
}

///Complexitate totala : O(2 * nlog2(n) + n) -> O(n(log2(n) + 1)) - > O(n(log2n)) < O(n^2)

int main()
{
    FILE* fin = fopen("expresie.in", "r");
    FILE* fout = fopen("expresie.out", "w");
    int n, m, A[101], B[101], i;
    fscanf(fin, "%d%d", &n, &m);

    for(i = 0; i < n; fscanf(fin, "%d", &A[i++]));
    for(i = 0; i < m; fscanf(fin, "%d", &B[i++]));

    quick_sort(A, 0, n - 1);
    quick_sort(B, 0, m - 1);


    int suma = 0;
    for(i = 0; i < n; printf("%d %d\n", A[n - i - 1], B[m - i -1]),i++)
        suma += A[n - i - 1] * B[m - i - 1];
    printf("%d", suma);

    return 0;
}

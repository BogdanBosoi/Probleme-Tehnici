#include <stdio.h>
#include <stdlib.h>

int *Citire(int *Vector, int *numarElem, int *element)
{
    FILE *fin = fopen("binary.in", "r");
    fscanf(fin, "%d", numarElem);

    Vector = (int*)malloc(sizeof(int) * *numarElem);

    short contor;
    for(contor = 0; contor < *numarElem; fscanf(fin, "%d", &Vector[contor++]));
    fscanf(fin, "%d", element);

    fclose(fin);
    return Vector;
}

int bin_search(int *Vector, int st, int dr, int element)
{
    int mijloc;

    if(st > dr) return -1;
    else
    {
        mijloc = (st + dr) / 2;

        if(Vector[mijloc] == element) return mijloc;
        else if(Vector[mijloc] > element) bin_search(Vector, st, mijloc - 1, element);
        else bin_search(Vector, mijloc + 1, dr, element);
    }
}

int main()
{
    int Vector, numarElem, element;
    Vector = Citire(Vector, &numarElem, &element);
    int vvv[numarElem];
    printf("%d", bin_search(Vector, 0, numarElem - 1, element) + 1);
    free(Vector);
    return 0;
}

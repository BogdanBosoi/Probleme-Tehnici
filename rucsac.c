#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int G, c;
    int ID;
}obiect;

int obCmp(const void * a, const void * b)
{
   obiect va = *(obiect*)a;
   obiect vb = *(obiect*)b;
   if((float)va.G/va.c < (float)vb.G/vb.c)
    return 1;
   if((float)va.G/va.c > (float)vb.G/vb.c)
    return -1;
   return 0;
}

int main()
{
    FILE *intrare = fopen("intrare.in", "r");
    int i = 0, rucsac, n;
    fscanf(intrare, "%d%d", &rucsac, &n);
    obiect *obVect = (obiect*)malloc(sizeof(obiect) * (n +1) );
    for(; i < n; fscanf(intrare, "%d%d", &obVect[i].G, &obVect[i].c), obVect[i].ID = i++);
    fclose(intrare);

    qsort(obVect, n, sizeof(obiect), obCmp);

    for(i = 0; i < n; printf("%d %d\n", obVect[i].c, obVect[i].G), i++);

    int nrOb = 0;
    for(i = 0; i < n; i++)
        if(rucsac - obVect[i].G > 0)
            {
                printf("Castig %d: 100%%\n", obVect[i].ID);
                rucsac -= obVect[i].G;
                nrOb++;
            }
        else
            {
                printf("Castig %d: %.1f%%\n", obVect[i].ID, ((float)rucsac/obVect[i].G) * 100);
                break;
            }
    printf("%d\n", nrOb);

    return 0;
}

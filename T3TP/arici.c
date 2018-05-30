#include <stdio.h>
#include <stdlib.h>

int **Citire(int **Harta, int *lung, int *lat)
{

    FILE *fin = fopen("arici.in", "r");
    fscanf(fin, "%d", lung);
    fscanf(fin, "%d", lat);

    Harta = (int**)malloc(sizeof(int*) * (*lung + 1));

    int contor = 0;
    for(; contor <= *lung + 1; contor++)
        Harta[contor] = (int*)calloc(*lat, sizeof(int));
    int contorj = 0;

    for(contor = 1; contor <= *lung; contor++)
        for(contorj = 1; contorj <= *lat; contorj++)
            fscanf(fin, "%d", &Harta[contor][contorj]);

    return Harta;
}

int fructeMax(int **Harta, int lung, int lat)
{
    int **SumHarta;
    SumHarta = (int**)malloc(sizeof(int*) * (lung + 1));
    int contorj = 1;
    int contor = 0;
    for(; contor <= lung; contor++)
        SumHarta[contor] = (int*)calloc(lat, sizeof(int));

    for(contor = 1; contor <= lung; contor++)
        for(contorj = 1; contorj <= lat; contorj++)
        {
            SumHarta[contor][contorj] = Harta[contor][contorj];
            if(SumHarta[contor - 1][contorj] >= SumHarta[contor][contorj - 1])
                SumHarta[contor][contorj] += SumHarta[contor - 1][contorj];
            else
                SumHarta[contor][contorj] += SumHarta[contor][contorj - 1];
        }
    for(contor = 0; contor <= lung; contor++)
        free(SumHarta[contor]);
    free(SumHarta);

    return SumHarta[lung][lat];
}

void Afisare(int valoare)
{
    FILE *fout = fopen("arici.out", "w");
    fprintf(fout, "%d", valoare);
    fclose(fout);
}

int main()
{
    int **Harta, lung, lat;
    Harta = Citire(Harta, &lung, &lat);
    int contor = 0, contorj = 0;
    Afisare(fructeMax(Harta, lung, lat));

    for(contor = 0; contor <= lung; contor++)
        free(Harta[contor]);
    free(Harta);
    return 0;
}

///Avem un sir de n numere nu neaparat distincte
///Vrem sa vedem care element apare de [n/2] + 1 ori

#include <stdio.h>
#include <stdlib.h>

int citire(int *elemVect, int *n)
{
    ///Citim vectorul, dupa ce l-am alocat dinamic
    FILE *data = fopen("data.in", "r");
    fscanf(data, "%d", n);
    elemVect = (int*)malloc(sizeof(int) * (*n));
    short i = 0;
    for(; i < *n;  fscanf(data, "%d", &elemVect[i++]));
    fclose(data);
    return elemVect;
}


int cmp(const void *a, const void *b)
{
    ///Comparator pentru qsort
    return ( *(int*)a - *(int*)b);
}


int nPatrat(int *elemVect, int n)
{
    ///Cerinta 1
    ///Numaram fiecare element din vector si il afisam pe cel care apare de [n/2] + 1 ori
    ///Complexitate timp   : O(n^2)
    ///Complexitate memorie: O(n)
    int counter = 0, maxCounter = 0;
    int maxElem = elemVect[0];
    int i, j;

    for(i = 0; i < n; counter = 0, i++)
    {
        for(j = 0; j < n; j++)
            if(elemVect[i] == elemVect[j])
                counter++;
        if(maxCounter < counter)
            maxCounter = counter, maxElem = elemVect[i];
    }
    if(maxCounter < n/2 + 1)                            ///[n/2] e echivalentul lui floor(n/2), dar lucram oricum cu int care ia partea intreaga a numerelor pozitive
        return -1;
    return maxElem;

}

int nlognSortare(int *elemVect, int n)
{
    ///Cerinta 2
    ///Sortam vectorul cu qsort
    ///Parcurgem vectorul element cu element si afisam numarul care apare de cele mai multe ori consecutiv
    ///Complexitate timp   : O(n*log(2)n)
    ///Complexitate memorie: O(n)
    int i = 1, elementMax, nrMax = 0, nr = 1;
    qsort(elemVect, n, sizeof(int), cmp);
    for(; i < n; i++)
    {
        if(elemVect[i] == elemVect[i - 1])
            nr++;
        else
            {
                if(nrMax < nr)
                {
                    nrMax = nr;
                    elementMax = elemVect[i - 1];
                }
                nr = 1;
            }
    }
    if(nrMax < n/2 + 1)
        return -1;
    return elementMax;
}

int eficientLiniar(int *elemVect, int n)
{
    ///Cerinta 3
    ///Parcurgem vectorul element cu element "grupand" elementele diferite si "anulandu-le"
    ///Daca cel ramas la final e si majoritar([n/2] + 1, parcurgem vectorul inca o data)
    ///Atunci reprezinta solutia problemei
    ///Complexitate timp:    O(n)
    ///Complexitate memorie: O(n)
    short int i = 1, elemCrt = elemVect[0], elemMax, nrCrt = 1;

    for(; i < n; i++)
    {
        if(elemVect[i] == elemCrt)
            nrCrt++;
        else
            nrCrt--;
        if(nrCrt <= 0)
            elemCrt = elemVect[i], nrCrt = 1;
    }


    short int counter = 0;
    for(i = 0; i < n; i++)
        if(elemVect[i] == elemCrt)
            counter++;
    if(counter < n/2 + 1)
        return -1;
    return elemCrt;
}

int linfaravectori(int n)
{
    ///Cerinta 4
    ///Solutia "eficienta" in O(1) consta in efectiv parcurgerea de 2 ori a fisierului
    ///prima data pentru realizarea algoritmului de la cerinta 3
    ///a doua oara pentru verificare
    ///Complexitate timp:    O(n)
    ///Complexitate memorie: O(1)
    FILE *data = fopen("data.in", "r");
    fscanf(data, "%d", &n);
    int elemCrt, elemMax;
    short int i = 1, nrCrt;
    fscanf(data, "%d", &elemMax);
    nrCrt = 1;
    for(; i < n; i++)
    {
        fscanf(data, "%d", &elemCrt);
        if(elemMax == elemCrt)
                nrCrt++;
        else
            nrCrt--;
        if(nrCrt <= 0)
            elemMax = elemCrt, nrCrt = 1;
    }
    fseek(data, 0, SEEK_SET);
    fscanf(data, "%d", &n);
    short int counter = 0;
    for(i = 0; i < n; fscanf(data, "%d", &elemCrt), i++)
        if(elemMax == elemCrt)
            counter++;

    if(counter < n/2 + 1)
        return -1;
    fclose(data);
    return elemMax;
}



void Afisare(int *elemVect, int n)
{
    FILE *data = fopen("data.out", "w");
    fprintf(data, "n^2:\t\t%d\nnlogn:\t\t%d\nnlin:\t\t%d\nnlinO(1):\t%d\n"  , nPatrat(elemVect, n)
                                                                            , nlognSortare(elemVect, n)
                                                                            , eficientLiniar(elemVect, n)
                                                                            , linfaravectori(n));
    fclose(data);

}

int main()
{
    int *elemVect, n;
    elemVect = citire(elemVect, &n);
    Afisare(elemVect, n);
    return 0;
}

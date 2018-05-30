#include <stdio.h>
#include <stdlib.h>

int* Citire(int *elemVector, int *nrElem, int *deCautat)
{
    scanf("%d", nrElem);
    elemVector = (int*)malloc(sizeof(int) * *nrElem);
    int contor = 0;
    for(; contor < *nrElem; scanf("%d", &elemVector[contor++]));
    scanf("%d", deCautat);
    return elemVector;
}

int numaraElemente(int *elemVector, int nrElem, int indice)
{
    ///Toate elementele egale dintr-un sir ordonat (des)crescator vor fi pe indici adiacenti
    int nrGasit = 1;
    if(indice == -1)
        return -1;
    int contor = indice + 1;
    for(; elemVector[contor] == elemVector[indice]; contor++, nrGasit++);
    contor = indice - 1;
    for(; elemVector[contor] == elemVector[indice]; contor --, nrGasit++);
    return nrGasit;
}

int CautaBinar(int *elemVector, int st, int dr, int deCautat)
{
    if (dr >= st)
    {
        int mid = st + (dr - st)/2;
        if (elemVector[mid] == deCautat)
            return mid;
        else if(elemVector[mid] < deCautat)
            return CautaBinar(elemVector, mid + 1, dr, deCautat);
        else
            return CautaBinar(elemVector, st, mid - 1, deCautat);
    }
    return -1;
}

int main()
{
    int *elemVector, nrElem, deCautat;
    elemVector = Citire(elemVector, &nrElem, &deCautat);
    printf("%d", numaraElemente(elemVector, nrElem, CautaBinar(elemVector, 0, nrElem - 1, deCautat)));  ///Caut Binar elementul si dupa ce l-am gasit, parcurg vectorul din indicele lui la stanga si la dreapta sa si numar elementele similare
    free(elemVector);
    return 0;
}

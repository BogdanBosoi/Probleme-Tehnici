#include <stdio.h>
#include <stdlib.h>

int* Citire(int *elemVector, int *nrElem)
{
    scanf("%d", nrElem);
    elemVector = (int*)malloc(*nrElem * sizeof(int));
    int contor;
    for(contor = 0; contor < *nrElem; scanf("%d", &elemVector[contor++]));
    return elemVector;

}

int inflexiune(int *elemVect, int st, int dr)
{
    if (st == dr) return st;                ///Daca e un singur element
    if (dr == st + 1)                       ///Daca sunt 2 elemente
        if (elemVect[st] > elemVect[dr])
            return st;
        else
            return dr;
    ///Daca sunt 3 elemente sau mai multe
    int mid = st + (dr - st)/2;

    if(elemVect[mid] > elemVect[mid + 1] && elemVect[mid] > elemVect[mid - 1])  ///Daca cel din mijloc e mai mare ca vecinul din stanga si cel din dreapta, atunci e punct de "inflexiune"
        return mid;
    if(elemVect[mid] > elemVect[mid + 1] && elemVect[mid] < elemVect[mid - 1])  ///Daca cel din mijloc se afla in sirul descrescator -> mergem in stanga
        return inflexiune(elemVect, st, mid - 1);
    else                                                                        ///Daca cel din mijloc se afla in sirul crecator -> mergem in dreapta
        return inflexiune(elemVect, mid + 1, dr);
}

int main()
{
    int *elemVector, nrElem;
    elemVector = Citire(elemVector, &nrElem);
    int inflex = inflexiune(elemVector, 0, nrElem - 1);
    printf("%d %d", inflex + 1, elemVector[inflex]);
    return 0;
}

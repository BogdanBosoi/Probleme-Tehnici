#include <stdio.h>
#include <stdlib.h>

int **Citire(int **Tabla, int *nrElem)
{
    FILE *fin = fopen("bonus.in", "r");
    fscanf(fin, "%d", nrElem);
    Tabla = (int**)malloc(sizeof(int*) * (*nrElem + 1));
    int contor = 0, contorj;

    for(contor = 0; contor <= *nrElem + 1; contor++)
        Tabla[contor] = (int*)calloc((*nrElem + 2), sizeof(int));

    for(contor = 1; contor <= *nrElem; contor++)
        for(contorj = 1; contorj <= *nrElem; contorj++)
            fscanf(fin, "%d", &Tabla[contor][contorj]);
    fclose(fin);
    return Tabla;
}

void Parcurgere(int **Tabla, int nrElem)
{
    int contor, contorj;
    int **TablaPartiala;
    ///Alocare dinamica
    TablaPartiala = (int**)malloc(sizeof(int*) * nrElem);
    for(contor = 0; contor <= nrElem; contor++)
        TablaPartiala[contor] = (int*)calloc((nrElem + 2),sizeof(int));

    ///Construiesc matricea de drum optim maximal cu regulile impuse
    for(contor = 1; contor <= nrElem; contor++)
    {
        for(contorj = 1; contorj <= nrElem; contorj++)
        {
        if(Tabla[contor][contorj] == 0)
            TablaPartiala[contor][contorj] = TablaPartiala[contor - 1][contorj];
        else if(Tabla[contor][contorj] == 1)
            if(TablaPartiala[contor - 1][contorj - 1] >= TablaPartiala[contor - 1][contorj + 1])
                TablaPartiala[contor][contorj] = TablaPartiala[contor - 1][contorj - 1] + 1;
            else if(TablaPartiala[contor - 1][contorj - 1] < TablaPartiala[contor - 1][contorj + 1])
                TablaPartiala[contor][contorj] = TablaPartiala[contor - 1][contorj + 1] + 1;
        }
    }
    ///Iau maximul de pe ultima linie pentru a reconstrui solutia/una dintre solutii i.e. drumul optim
    int indiceMax = 1, elemMax = -1;
    for(contor = 2; contor <= nrElem; contor++)
        if(TablaPartiala[nrElem][contor] > TablaPartiala[nrElem][indiceMax])
            indiceMax = contor;

    contorj = nrElem;

    ///Mereu vectorul solutie va avea nrElem elemente, valoarea = numarul liniei, iar indicile = numarul coloanei
    int *solutie = (int*)malloc(sizeof(int) * nrElem + 1);
    ///Reconstruiesc solutia/una dintre solutii pentru drum optim si o pun in vectorul "solutie", pentru a o afisa invers.
    while(contorj >= 1)
    {
        if(TablaPartiala[contorj][indiceMax] == (TablaPartiala[contorj - 1][indiceMax - 1] + 1))
            solutie[contorj] = indiceMax--;
        else if(TablaPartiala[contorj][indiceMax] == (TablaPartiala[contorj - 1][indiceMax + 1] + 1))
            solutie[contorj] = indiceMax++;
        else
            solutie[contorj] = indiceMax;
    contorj--;
    }

    FILE *fout = fopen("bonus.out", "w");
    ///Afisez solutia/una dintre solutii optima/optime
    for(contor = 1; contor <= nrElem; contor++)
        fprintf(fout, "%d %d\n", contor, solutie[contor]);
    fprintf(fout, "Sunt %d piese.\n", TablaPartiala[nrElem][solutie[nrElem]]);
    ///Eliberari de memorie
    fclose(fout);
    for(contor = 0; contor <= nrElem; contor++)
        free(TablaPartiala[contor]);
    free(TablaPartiala);
    free(solutie);

}

int main()
{
    int nrElem, **Tabla;
    int contor;
    Tabla = Citire(Tabla, &nrElem);
    Parcurgere(Tabla, nrElem);
    for(contor = 0; contor <= nrElem; contor++)
        free(Tabla[contor]);
    free(Tabla);
    return 0;
}

///Ai un triunghi dreptunghic de n linii, iar linia k are k coloane, elementele sunt reale sau intregi, whatever
///Se cere suma maxima parcurgand triunghiul din coltul stanga sus, deplasandu-te doar (in i + 1, j) sau (i + 1, j + 1)

#include <stdio.h>
#include <stdlib.h>

int M[101][101], n, S[101][101];

///Complexitate patratica O(n^2)

int main()
{
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) ///incep ca milogul cu forul de la 1 ca sa nu mai bordez matricea sa iasa finut cu S
        for(j = 1; j <= i; j++)
            scanf("%d", &M[i][j]);
    S[1][1] = M[1][1];
    for(i = 2; i <= n; i++)
        for(j = 1; j <= i; j++)
            if(S[i - 1][j] >= S[i - 1][j - 1])
                S[i][j] = M[i][j] + S[i - 1][j];
            else
                S[i][j] = M[i][j] + S[i - 1][j - 1];
    int max = -1;
    for(i = 1; i <= n; i++, printf("\n"))
        for(j = 1; j <= i; j++)
            printf("%d ", S[i][j]);
    for(i = 1; i <= n; i++)
            if(max < S[n][i])
                max = S[n][i];
    printf("%d", max);

    return 0;
}

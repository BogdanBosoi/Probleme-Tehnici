///Complexitate: ¯\_(ツ)_/¯

#include <stdio.h>
#include <stdlib.h>

int st[101], M[101][2], R;

int valid(int k, int n)
{
    int suma, i;
    for(i = 1, suma = 0; i <= n; i++)
        suma += st[i];
    if (suma == R)
        return 1;
    return 0;
}

void tiparire(int k)
{
    int i;
    for(i = 1; i <= k; printf("%d ", st[i++]));
    printf("\n");
}

void bkt(int k, int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        st[k] = M[i][0] - M[i][1]++;
        if(M[i][1] > M[i][0])
            M[i][1] = 0;
        if(k != n)
            bkt(k + 1, n);
        else
        if(valid(k, n))
                tiparire(k);
    }
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i = 1; i <= n; M[i++][1] = 0)
        scanf("%d", &M[i][0]);
    scanf("%d", &R);
    bkt(1, n);
    return 0;
}

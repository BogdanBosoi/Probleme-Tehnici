#include <stdio.h>
#include <stdlib.h>

int st[100];
int suma;
int v[101];
int m;
int valid(int k)
{
    int i;
    for(i = 1; i < k; i++)
        if(st[i] == st[k]) return 0;
    return 1;
}

int validSuma(int k)
{
    int sumapart = 0, i;
    for(i = 1; i < k; i++)
        if(st[i] >= st[i + 1]) return 0;
    for(i = 1; i <= k; i++)
        sumapart += st[i];
    if(sumapart == suma)
        return 1;
    return 0;
}

void tiparire(int k)
{
    int i;
    for(i = 1; i <= k; i++)
        printf("%d ", st[i]);
    printf("\n");
}

void bkt(int k, int n)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        st[k] = v[i];
        if(validSuma(k))
                tiparire(k);
            else
                if(k < m)
                    bkt(k + 1, n);
    }
}


int main()
{
    int n;
    scanf("%d %d %d", &n, &suma, &m);
    int i = 1;
    for(; i <= n; i++)
        scanf("%d", &v[i]);
    bkt(1, n);
    return 0;
}

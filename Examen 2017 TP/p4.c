#include <stdlib.h>
#include <stdio.h>


int main()
{
    int v[101], n;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n; scanf("%d", &v[i++]));
    int changer = 1, aux;
    for(i = 0; i < n - 1; changer *= -1, i++)
        if(v[i] * changer > v[i + 1]*changer)
        {
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }

    for(i = 0; i < n; printf("%d ", v[i++]));
    printf("\n");


    return 0;
}

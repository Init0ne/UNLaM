//Piramide de asteriscos

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int f, e, a, n;

    printf("\n Ingrese un numero mayor a 0 para dibujar una piramide : ");
    scanf("%d", &n);

    if(f <= n)
    {
        for(f = 0; f <= n; f++)
        {
            for(e = 0; e < n - f; e++)
            {
                printf(" ");
            }

            for(a = 1; a < f * 2; a++)
            {
                printf("*");
            }
            printf("\n");
        }

    }
    if(f == n + 1)
    {
        for(f = n; f >= 0; f--)
        {
            for(e = 0; e < n - f; e++)
            {
                printf(" ");
            }

            for(a = 1; a < f * 2; a++)
            {
                printf("*");
            }
            printf("\n");
        }
    }


    system ("pause");
    return 0;
}

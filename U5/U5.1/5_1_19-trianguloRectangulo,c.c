//Triangulo rectangulo con asteriscos.

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int i, j, n;

    printf("\n Ingrese un numero real : ");
    scanf("%d", &n);

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    system("pause");
    return 0;
}

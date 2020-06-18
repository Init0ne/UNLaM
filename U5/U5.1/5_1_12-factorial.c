//Factoriales

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, fact = 1;

    printf("\n Ingrese un numero entero : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        fact *= i;
    }

    printf("\n El factorial de %d es %d ! \n", n, fact);

    system("pause");
    return 0;
}

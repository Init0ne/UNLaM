//Promedio entre pares

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int i, cont, sumaPar, num;
    float promPar;

    for(i = 1; i <= 50; i++)
    {
        printf("\n Ingrese un numero : ");
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            sumaPar += num;
            cont ++;
        }
    }

    promPar = sumaPar / cont;

    printf("\n El promedio de los numeros pares es : %.2f \n", promPar);

    system("pause");
    return 0;
}

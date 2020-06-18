//Programa para reconocer si un numero es divisible por otro.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1, n2;

    //Ingresa dos numeros
    printf("\n Ingrese un numero : ");
    scanf("%d", &n1);
    printf("\n Ingrese otro numero : ");
    scanf("%d", &n2);

    //Condiciones
    if (n1 % n2 == 0 || n2 % n1 == 0)
    {
        if (n1 % n2 == 0)
        {
            printf("\n El numero %d es divisible por el numero %d \n", n1, n2);
        }
        else
        {
            printf("\n El numero %d es divisible por el numero %d \n", n2, n1);
        }
    }
    else
    {
        printf("\n No se pueden dividir estos numeros entre si, intenta con otros! \n");
    }

    system("pause");
    return 0;
}

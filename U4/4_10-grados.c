//Grados a radianes y viceversa.

#define Pi 3.14159
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cod;
    float valor;

    //El usuario ingresa el valor a convertir
    printf("Ingrese el valor a convertir : ");
    scanf("%f", &valor);
    //Ingresa el codigo
    printf("\n Ingrese el codigo, '1' para Grados sexagesimales o '2' para convertir en radianes : ");
    scanf("%d", &cod);

    switch(cod)
    {
        case 1 : valor = valor * 180 / Pi;
        printf("\n El resultado en grados es : %.2f \n", valor);
        break;

        case 2 : valor = valor * Pi / 180;
        printf("\n El resultado en radianes es : %.2f \n", valor);
        break;

        default : printf("\n El codigo ingresado es incorrecto. \n ");
    }

    system("pause");
    return 0;
}

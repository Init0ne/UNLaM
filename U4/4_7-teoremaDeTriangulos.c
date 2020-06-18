//Programa para reconocer triangulos por sus lados

#include<stdio.h>
#include<stdlib.h>
int main()
{
    unsigned int a, b, c;

    //Ingresa valores en variables
    printf("\n Ingrese el valor del lado A : ");
    scanf("%d", &a);
    printf("\n Ingrese el valor del lado B : ");
    scanf("%d", &b);
    printf("\n Ingrese el valor del lado C : ");
    scanf("%d", &c);

    //Calcula si es un triangulo
    if (a + b > c && a + c > b && b + c > a)
    {
        printf("\n Es un triangulo. \n");
    }
    else
    {
        printf("\n No es un triangulo. \n");
    }

    system("pause");
    return 0;
}

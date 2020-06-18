#include<stdio.h>
#include<stdlib.h>
int main()
{
    float Nota1, Nota2, Promedio;

    // El usuario introduce la primer nota
    printf("Resultado de primera evaluacion : ");
    scanf("%f",&Nota1);

    // El usuario introduce la segunda nota
    printf("\nResultado de la segunda evaluacion : ");
    scanf("%f",&Nota2);

    Promedio = (Nota1 + Nota2) / 2;

    // El usuario recibe su promedio de notas
    printf("\nEl promedio es de: %.2f \n", Promedio);
    getch();
    system("pause");
    return 0;
}

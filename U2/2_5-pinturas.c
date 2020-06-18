#include<stdio.h>
#include<stdlib.h>
int main()
{
    int Tarros, Tarros_1, Tarros_4, Tarros_20;

    //El usuario ingresa la cant de tarros en stock
    printf("Ingrese la cantidad de tarros en el inventario : ");
    scanf("%d", &Tarros);

    Tarros_1 = (Tarros * 50) / 100;
    Tarros_4 = (Tarros * 30) / 100;
    Tarros_20 = Tarros - Tarros_1 - Tarros_4;

    printf("\nHay %d tarros de 1L\n", Tarros_1);
    printf("\nHay %d tarros de 4L\n", Tarros_4);
    printf("\nHay %d tarros de 20L\n", Tarros_20);

    getch();
    system("pause");
    return 0;
}

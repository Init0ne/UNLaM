#include<stdio.h>
#include<stdlib.h>
int main()
{
    float Precio, Codigo, Descuento, Total;


    printf("Ingrese el precio : ");
    scanf("%f", &Precio);
    printf("Ingrese el codigo : ");
    scanf("%f", &Codigo);

    Total = (Precio - (Precio * Codigo * 20 / 100));

    printf("\n El total a pagar es : %.2f \n", Total);

    getch();
    system("pause");
    return 0;
}

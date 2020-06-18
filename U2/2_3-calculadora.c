#include<stdio.h>
#include<stdlib.h>
int main()
{
    int Num1, Num2, Suma, Producto, Cociente, Resto;

    printf("\nIngrese el primer numero : ");
    scanf("%d", &Num1);

    printf("\nIngrese el segundo numero : ");
    scanf("%d", &Num2);

    //Suma
    Suma = Num1 + Num2;
    //Producto
    Producto = Num1 * Num2;
    //Cociente
    Cociente = Num1 / Num2;
    //Resto
    Resto = Num1 % Num2;

    //Imprime el resultado de los calculos
    printf("\nEl resultado de la suma es : %d \n ", Suma);
    printf("\nEl resultado de la multiplicacion es : %d \n ", Producto);
    printf("\nEl resultado de la division es : %d \n ", Cociente);
    printf("\nEl resto de la division es : %d \n ", Resto);

    getch();
    system("pause");
    return 0;
}

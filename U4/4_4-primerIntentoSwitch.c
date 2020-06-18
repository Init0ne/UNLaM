//Determina varias opciones dependiendo el resultado

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, n3;

    //El usuario ingresa  tres numeros enteros.
    printf( "\n   Introduzca el primer nucmero (entero): ");
    scanf( "%d", &n1 );
    printf( "\n   Introduzca el segundo nucmero (entero): ");
    scanf( "%d", &n2 );
    printf( "\n   Introduzca el tercer nucmero (entero): ");
    scanf( "%d", &n3 );

    if(n1 > n3 && n2 > n3)
    {
        printf("\n Mayores al tercero. \n");
    }
    if(n1 == n2 == n3)
    {
        printf("\n Tres iguales. \n");
    }
    if(n1 < n3 || n2 < n3)
    {
        printf("\n Alguno es menor. \n");
    }

    getch();
    system("pause");
    return 0;
}

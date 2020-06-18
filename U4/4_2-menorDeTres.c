#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf( "\n   Introduzca el primer nucmero (entero): ");
    scanf( "%d", &n1 );
    printf( "\n   Introduzca el segundo nucmero (entero): ");
    scanf( "%d", &n2 );
    printf( "\n   Introduzca el tercer nucmero (entero): ");
    scanf( "%d", &n3 );

    if(n1 < n2 && n1 < n3)
    {
        printf("\n El primer numero es el mas chico. \n");
    }
    else {
        printf("\n El primer numero no es el mas chico. \n");
    }
    getch();
    system("pause");
    return 0;
}

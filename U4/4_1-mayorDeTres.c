#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, n3, mayor;

    printf( "\n   Introduzca el primer nucmero (entero): ");
    scanf( "%d", &n1 );
    printf( "\n   Introduzca el segundo nucmero (entero): ");
    scanf( "%d", &n2 );
    printf( "\n   Introduzca el tercer nucmero (entero): ");
    scanf( "%d", &n3 );

    if ( n1 > n2 )

        if ( n1 > n3 )
            mayor = n1;
        else
            mayor = n3;

    else

        if ( n2 > n3 )
            mayor = n2;
        else
            mayor = n3;

    printf( "\n   %d es el mayor. \n" , mayor );

    getch();
    system("pause");
    return 0;
}

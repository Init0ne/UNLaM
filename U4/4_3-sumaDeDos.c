#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, n3, suma1, suma2, suma3;

    printf( "\n   Introduzca el primer nucmero (entero): ");
    scanf( "%d", &n1 );
    printf( "\n   Introduzca el segundo nucmero (entero): ");
    scanf( "%d", &n2 );
    printf( "\n   Introduzca el tercer nucmero (entero): ");
    scanf( "%d", &n3 );

    suma1 = n1 + n2;
    suma2 = n1 + n3;
    suma3 = n2 + n3;

    if(suma1 == n1 || suma1 == n2 || suma1 == n3)
    {
        printf("\n La suma de %d y %d = %d \n", n1, n2, suma1);
    }
    else{
        if(suma2 == n1 || suma2 == n2 || suma2 == n3)
        {
            printf("\n La suma de %d y %d = %d \n", n1, n3, suma2);
        }
        else{
            if(suma3 == n1 || suma3 == n2 || suma3 == n3)
            {
                printf("\n La suma de %d y %d = %d \n", n2, n3, suma3);
            }
            else{
                printf("\n Ninguno de los numeros es la suma de los demas. \n");
            }
        }
    }

    getch();
    system("pause");
    return 0;
}

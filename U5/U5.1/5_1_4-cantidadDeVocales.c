//Cantidad de vocales

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int i, cont;
    char letra;

    cont = 0 ;

    for (i = 1; i <= 100; i++)
    {
        printf("\n Ingrese una letra : ");
        fflush(stdin);
        scanf("%c", &letra);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        {
            cont ++;
        }
    }

    printf("\n La cantidad de vocales fue de : %d \n", cont);

    system("pause");
    return 0;
}

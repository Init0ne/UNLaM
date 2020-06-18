//Matriz de tablas

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int f, c, fila;

    for(c = 1; c < 10; c ++)
    {
        printf("\n %d ", c);

        for(f = 2; f < 10; f++)
        {

            fila = f * c;
            printf("\t %d", fila);
        }

    }

    system("pause");
    return 0;
}

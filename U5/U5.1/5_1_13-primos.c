//Primos

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i, cont = 0;

    for(i = 2; i < 100; i++)
    {
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
        {
            cont ++;
            printf("\n %d es un numero primo! \n", i);
        }
        else
        {
            if(i == 2 || i == 3 || i == 5 || i == 7)
               {
                    cont++;
                    printf("\n %d es un numero primo! \n", i);
               }
        }
    }
    printf("\n La cantidad de numeros primos entre 1 y 100 es de %d \n", cont);

    system("pause");
    return 0;
}

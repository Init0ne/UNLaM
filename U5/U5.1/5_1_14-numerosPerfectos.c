//Numeros Perfectos.

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, j, cont = 0, suma = 0;

    printf ("Numeros perfectos entre 1 y 8000: \n");
    for (i=2;i<=8000;i++)
    {
        for (j=1;j<i;j++)
        {
            if (i%j==0)
               suma += j;
        }
        if (suma==i)
        {
            printf ("%d\n", i);
            cont ++;
        }
        suma=0;
    }
    if (cont>0)
        printf ("\nEntre 1 y 8000 hay %d numeros perfectos.\n", cont);

    system ("pause");
    return 0;
}


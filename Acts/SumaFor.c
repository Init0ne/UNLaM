#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int suma, i,cont;

    suma = 0;
    cont = 0;

    for(i = 1; i <= 4; i++)
    {
        suma += i;
        cont += 1;
    }

    printf("\n La suma es %d \n", suma);
    printf("\n Se sumaron %d numeros \n", cont);

    system ("pause");
    return 0;

}

//Capicuas simples o quintuples

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, dMil, mil, cent, dec, uni, inverso;

    printf("\nIngrese un numero de 5 cifras : ");
    scanf("%d", &n);

    //Descoponedor
    dMil = n / 10000 ;
    mil =  n % 10000 / 1000 * 10;
    cent = n % 1000 / 100 * 100;
    dec = n % 100 / 10 * 1000 ;
    uni = n % 10 % 10 * 10000;
    //Armado de capicua
    inverso = uni + dec + cent + mil + dMil;

    //Condiciones
    if(uni / 10000 == dec / 1000 && dec / 1000 == cent / 100 && cent / 100 == mil / 10 && mil / 10 == dMil)
    {
        printf("\n El numero %d es un numero capicua quintuple! \n", n);
    }
    else
    {
        if(n == inverso)
        {
            printf("\n El numero %d es un numero capicua simple! \n", n);
        }
        else
        {
            printf("\n El numero %d no es capicua. \n", n);
        }
    }

    system("pause");
    return 0;
}

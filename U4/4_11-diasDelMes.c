//Ejercicio 4_11.
//Dias del mes incluso en bisiestos.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int year, month;

    //El usuario ingresa el ano
    printf("\n Ingrese el ano : ");
    scanf("%d", &year);
    //Ingresa el mes
    printf("\n Ingrese el mes : ");
    scanf("%d", &month);

    //Condiciones
    //Si el mes es febrero
    if (month == 2)
    {
        //si el ano es bisiesto
        if (year % 4 == 0 && year % 100 != 0)
        {
            printf("\n El mes %d del ano %d tiene 29 dias, es un ano bisiesto . \n", month, year);
        }
        else
        {
            printf("\n El mes %d del ano %d tiene 28 dias, no es un ano bisiesto. \n", month, year);
        }
    }
    else
    {
        //hasta julio
        if(month <= 7)
        {
            //si es par
            if (month % 2 == 0)
            {
                printf("\n El mes %d del ano %d tiene 30 dias. \n", month, year);
            }
            //si es impar
            else
            {
                printf("\n El mes %d del ano %d tiene 31 dias. \n", month, year);
            }
        }
        //despues de julio
        else
        {
            //si es par
            if (month % 2 == 0)
            {
                printf("\n El mes %d del ano %d tiene 31 dias. \n", month, year);
            }
            //si es impar
            else
            {
                printf("\n El mes %d del ano %d tiene 30 dias. \n", month, year);
            }
        }
    }

    system("pause");
    return 0;
}

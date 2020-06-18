//Funcion valida fecha

#include <stdio.h>
#include <stdlib.h>

int ValidaFecha(int,int,int);
int DiasDelMes(int,int);

int main ()
{
    int day, month, year, flag;

    flag = 0;

    while(flag == 0)
    {
        do{
        printf("\n Ingrese el dia :");
        scanf("%d", &day);
        }while(day < 1 || day > 31);

        do{
            printf("\n Ingrese el mes :");
            scanf("%d", &month);
        }while(month < 1 || month > 12);

        do{
            printf("\n Ingrese el ano :");
            scanf("%d", &year);
        }while(year < 1);

        flag = ValidaFecha(day, month, year);

        if(flag == 1)
        {
            printf(" \n La fecha ingresada es correcta! \n");
        }
        else
        {
            printf("\n La fecha ingresada es incorrecta! \n");
        }
    }
    
    system("pause");
    return 0;
}

int ValidaFecha (int day, int month, int year)
{
    int dias;

    dias = DiasDelMes(month, year);

    if(day <= dias)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DiasDelMes(int month, int year)
{   
    int dias;
    
    //Condiciones
    //Si el mes es febrero
    if (month == 2)
    {
        //si el ano es bisiesto
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            dias = 29;
        }
        else
        {
            dias = 28;
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
                dias = 30;
            }
            //si es impar
            else
            {
                dias = 31;
            }
        }
        //despues de julio
        else
        {
            //si es par
            if (month % 2 == 0)
            {
                dias = 31;
            }
            //si es impar
            else
            {
                dias = 30;
            }
        }
    }
    return dias;
}
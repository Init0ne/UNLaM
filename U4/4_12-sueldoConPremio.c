//Ejercicio 4_12.
//Sueldo con premio por horas

#include<stdio.h>
#include<stdlib.h>
int main()
{
    float cant_horas, val_horas, sueldo;


    //El usuario ingresa la cant de horas y el valor de la misma
    printf("\n Ingrese el total de horas trabajadas a continuacion : ");
    scanf("%f", &cant_horas);
    printf("\n Ingrese el valor por hora : ");
    scanf("%f", &val_horas);

    //trabajo mas de 50 horas
    if (cant_horas >= 50)
    {
        //tipo de premio
        if (cant_horas >= 150)
        {
            sueldo = cant_horas * val_horas + 1500;
        }
        else
        {
            sueldo = cant_horas * val_horas + 500;
        }
    }
    else
    {
        sueldo = cant_horas * val_horas;
    }

    printf("\n El empleado debe cobrar %.2f este mes. \n", sueldo);

    system("pause");
    return 0;
}

//Sueldo

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cantHijos, antig, cont = 0;
    float salarBasic, salarFinal, salarProm, salarEmp = 0, cincoPorcent, diezPorcent;
    char nuevo = 's', estudios;

    while(nuevo == 's')
    {
        //Ingreso de datos del empleado
        printf("\n Ingresar el sueldo basico del empleado a continuacion : ");
        scanf("%f", &salarBasic);
        printf("\n Antiguedad : ");
        scanf("%d", &antig);
        printf("\n Cantidad de hijos : ");
        scanf("%d", &cantHijos);
        printf("\n Tiene estudios superiores ? (S o N )");
        fflush(stdin);
        scanf("%c", &estudios);

        cincoPorcent = salarBasic * 5 / 100;
        diezPorcent = salarBasic * 10 / 100;
        salarFinal = salarBasic;

        //Condiciones de aumento
        if(antig >= 10)
        {
            salarFinal += diezPorcent;
        }
        if(cantHijos == 1)
        {
            salarFinal += cincoPorcent;
        }
        else
        {
            if(cantHijos >= 2)
            {
                salarFinal += diezPorcent;
            }
        }
        if(estudios == 's')
        {
            salarFinal += cincoPorcent;
        }
        cont ++;

        printf("\n Empleado n : %d", cont);
        printf("\n Sueldo basico : $ %.2f", salarBasic);
        printf("\n Sueldo final : $ %.2f", salarFinal);

        salarEmp += salarFinal;

        printf("\n Desea ingresar un nuevo empleado? (S o N) ");
        fflush(stdin);
        scanf("%c", &nuevo);
    }

    if(cont != 0)
    {
        salarProm = salarEmp / cont;
        printf("\n El salario promedio de la empresa es de $ %.2f \n", salarProm);
    }

    system("pause");
    return 0;
}

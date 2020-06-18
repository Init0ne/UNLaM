//Empleados empresa

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int leg = 1, leg_Max, c_Emp, c_M, c_F, ant, c_Ant, cat;
    float s_Basic, s_Final, s_Max;
    char sex;

    while(leg != 0)
    {
        c_Emp = 0; c_M = 0; c_F = 0; c_Ant = 0; s_Max = 0;

        printf("\n Ingrese los datos del empleado en el siguiente orden (Numero de legajo, sueldo basico, antiguedad, categoria y sexo ( m/f) :");
        scanf("%d%f%d%d", &leg, &s_Basic, &ant, &cat);
        fflush(stdin);
        scanf("%c", &sex);

        s_Final = s_Basic;

        if((leg >= 1000 && leg <= 5000) && s_Basic > 1000 && ant > 0 && (cat >= 1 && cat <= 5) && (sex == 'm' || sex == 'f'))
        {
            if(ant > 10)
            {
                s_Final += s_Basic * 10 / 100;
                c_Ant ++;
            }
            if(cat == 2 || cat == 3)
            {
                s_Final += 500;
            }
            else
            {
                if(cat == 4)
                {
                    s_Final += s_Basic * 10 / 100;
                }
                else
                {
                    if(cat == 5)
                    {
                        s_Final += s_Basic * 30 / 100;
                    }
                }
            }
            if(sex == 'm')
            {
                c_M ++;
            }
            else
            {
                c_F ++;
            }
            if(s_Final > s_Max)
            {
                s_Max = s_Final;
                leg_Max = leg;
            }

            printf("\n Sueldo a abonar : $ %.2f \n", s_Final);
            printf("\n Si desea finalizar ingrese 0 ");
            scanf("%d", &leg);
        }
        else
        {
            printf("\n Los valores ingresados fueron incorrectos. \n");
        }
    }

    if(c_M != 0 || c_F != 0)
    {
        printf("\n Cantidad de empleados con mas de 10 A de antiguedad : %d \n", c_Ant);
        printf("\n El mayor sueldo es el del empleado con el legajo n : %d por un valor de $ %.2f\n", leg_Max, s_Max);
        printf("\n La cantidad de hombres es de %d y la cantidad de mujeres es de %d \n", c_M, c_F);
    }

    system("pause");
    return 0;
}

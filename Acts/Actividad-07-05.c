//Actividad edades

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ddAct, ddBorn, ddEdad, ddMax, mmAct, mmBorn, mmEdad, mmMax, yyAct, yyBorn, yyEdad, yyMax, cont_P, n_P, suma_yy;
    float promedio_Edad;

    //Ingresa y se valida la fecha actual
    do{
        printf("\n Ingrese la fecha actual (dd-mm-aaaa) :");
        scanf("%d%d%d", &ddAct, &mmAct, &yyAct);
    }while((ddAct < 0 || ddAct > 31) || (mmAct < 0 || mmAct > 12) || (yyAct < 2020));

    //Ingresa y se valida la primer fecha a comparar
    do{
        printf("\n A continuacion ingrese la fecha de nacimiento de la persona a calcular (dd-mm-aaaa) : ");
        scanf("%d%d%d", &ddBorn, &mmBorn, &yyBorn);
    }while((ddBorn < 0 || ddBorn > 31) || (mmBorn < 0 || mmBorn > 12) || (yyBorn > yyAct));

    //Comienza ciclo para cada persona
    cont_P = 0; yyMax = 0; mmMax = 0; ddMax = 0;
    while(ddBorn !=0)
    {
        //Contador de personas que calcularon su edad
        cont_P ++;
        //Año
        yyEdad = yyAct - yyBorn;
        //Mes
        if(mmAct > mmBorn)
        {
            mmEdad = mmAct - mmBorn;
        }
        else
        {
            yyEdad -= 1;
            mmEdad = 12 + (mmAct - mmBorn);
        }
        //Dia
        if(ddAct > ddBorn)
        {
            ddEdad = ddAct - ddBorn;
        }
        else
        {
            mmEdad -= 1;
            ddEdad = 30 + (ddAct - ddBorn);
        }
        //Mayor edad
        if(yyEdad >= yyMax)
        {
            yyMax = yyEdad;
            if(mmEdad > mmMax)
            {
                mmMax = mmEdad;
                n_P = cont_P;
            }
            if(ddEdad > ddMax)
            {
                ddMax = ddEdad;
                n_P = cont_P;
            }
        }
        //Suma edad para promedio
        suma_yy += yyEdad;
        //Retorna edad
        printf("\n La persona nacida el %d - %d - %d tiene hoy %d años de edad y %d meses, %d dias. \n", ddBorn,mmBorn,yyBorn,yyEdad,mmEdad,ddEdad);
        //Calcula nueva persona si ddBorn != 0
        do{
            printf("\n A continuacion ingrese el dia de nacimiento de la persona a calcular '0' para finalizar : ");
            scanf("%d", &ddBorn);
        }while(ddBorn < 0 || ddBorn > 31);
        if(ddBorn != 0)
        {
            do{
                printf("\n A continuacion ingrese el mes : ");
                scanf("%d", &mmBorn);
            }while(mmBorn < 0 || mmBorn > 12);
            do{
                printf("\n Y por ultimo el ano : ");
                scanf("%d", &yyBorn);
            }while(yyBorn > yyAct);            
        }
    }
    //Mayor edad
    printf("\n La persona mas grande de las ingresadas es la numero %d, teniendo %d años, con %d meses y %d dias. \n", n_P,yyMax,mmMax,ddMax);
    //Proedio edad
    promedio_Edad = suma_yy / cont_P;
    printf("\n El proemdio de edad de la gente ingresada es de %.2f . \n", promedio_Edad);

    system("pause");
    return 0;
}

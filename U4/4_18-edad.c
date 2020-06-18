//Programa que calcula tu edad

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ddAct, ddBorn, ddEdad, mmAct, mmBorn, mmEdad, yyAct, yyBorn, yyEdad;

    //el usuario ingresa la fecha actual
    printf("\n Ingrese el dia actual : ");
    scanf("%d", &ddAct);
    printf("\n Ingrese el mes actual : ");
    scanf("%d", &mmAct);
    printf("\n Ingrese el ano actual : ");
    scanf("%d", &yyAct);

    //el usuario ingresa su fecha de nacimiento
    printf("\n Ingrese el dia de su nacimiento : ");
    scanf("%d", &ddBorn);
    printf("\n Ingrese el mes de su nacimieto : ");
    scanf("%d", &mmBorn);
    printf("\n Ingrese el ano de su nacimiento :");
    scanf("%d", &yyBorn);

    //edad en anos
    yyEdad = yyAct - yyBorn;

    //meses
    if(mmAct > mmBorn)
    {
        mmEdad = mmAct - mmBorn;
    }
    else
    {
        yyEdad -= 1;
        mmEdad = 12 + (mmAct - mmBorn);
    }

    //dias
    if(ddAct > ddBorn)
    {
        ddEdad = ddAct - ddBorn;
    }
    else
    {
        mmEdad -= 1;
        ddEdad = 30 + (ddAct - ddBorn);
    }

    //salida edad final
    printf("\n Usted tiene %d anos %d meses y %d dias! \n", yyEdad, mmEdad, ddEdad);

    system("pause");
    return 0;
}

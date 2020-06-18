//Act 2 del dia

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int leg, ingreso, cont_h, cont_y, leg_Max, y_Max;
    char sex, sex_Max, flag;
    float porcent_hombre;

    cont_h = 0; cont_y = 0;

    while(flag != 'F')
    {
        //Legajo
        do{
            printf("\n Ingrese el numero de legajo del estudiante : ");
            scanf("%d", &leg);
        }while(leg < 5000 || leg > 15000);
        //Ingreso 
        do{
            printf("\n Ingrese el ano de ingreso del estudiante : ");
            scanf("%d", &ingreso);
        }while(ingreso < 1990 || ingreso > 2013);
        //sexo
        do{
            printf("\n Ingrese el sexo del estudiante (M/H) :");
            fflush(stdin);
            scanf("%c", &sex);
            sex = toupper(sex);
        }while(sex != 'M' && sex != 'H');
        //Porcentaje de hombres ingresados en 2010
        if(ingreso == 2010)
        {
            cont_y ++;
            if(sex == 'H')
            {
                cont_h ++;
            }
        } 
        //Legajo mayor
        if(leg > leg_Max)
        {
            leg_Max = leg;
            sex_Max = sex;
            y_Max = ingreso;
        }
        //Continuar
        printf("\n Si desea continuar ingresando alumnos ingrese la letra 'S' de lo contrario 'F' :  ");
        fflush(stdin);
        scanf("%c", &flag);
        flag = toupper(flag);
    }

    //B- porcentaje de hombre en 2010
    if(cont_y > 0)
    {
        porcent_hombre = (float)cont_h *100 / cont_y;
        printf("\n El porcentaje de hombres ingresados en el 2010 es de %.2f porciento. \n", porcent_hombre);
    }

    //C- legajo mas alto y sus datos
    printf("\n El numero de legajo mas alto es %d ingresado en el ano %d y de sexo %c \n", leg_Max,y_Max,sex_Max);

    system("pause");
    return 0;
}

//Programa encuestas escuelas

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i, ddAct, mmAct, yyAct, ddBorn, mmBorn, yyBorn, ddEdad, mmEdad, yyEdad, ddMax, mmMax, yyMax, c_Col, n_Esc, c_Alum, c_T, c_N, cont_Al_N, cont_F_T, cont_tot, dni, cont_F, cont_Mal, cont_Mal_Tot, cont_Buen, cont_Buen_Max, n_Esc_Buen, cont_Al;
    char espe, sex, opi;
    float porcent_enc, porcent_M_T_Enc, porcent_Mal;

    //Ingresa fecha actual y cantidad de colegios
    do{
        printf("\n Ingrese la fechha actual (dd-mm-aaaa) : ");
        scanf("%d%d%d", &ddAct, &mmAct, &yyAct);
        printf("\n Ingrese la cantidad de colegios entrevistados : ");
        scanf("%d", &c_Col);
    }while((ddAct < 1 || ddAct > 31) || (mmAct < 1 || mmAct > 12) || yyAct < 2020 || c_Col < 1);

    //Ingres datos para cada colegio entrevistado
    c_T = 0; c_N = 0; cont_F = 0; cont_Buen = 0; cont_Al = 0; cont_Buen_Max = 0; cont_Mal = 0; cont_Al_N = 0; cont_F_T = 0; cont_tot = 0; cont_Mal_Tot = 0; ddMax = 0; mmMax = 0; yyMax = 0;
    for(i = 1; i <= c_Col; i++)
    {
        do{
            printf("\n Ingrese el numero de la escuela numero %d y la cantidad de alumnos :", i);
            scanf("%d%d", &n_Esc, &c_Alum);
            printf("\n Indique si es una escuela tecnica (T/N) :");
            fflush(stdin);
            scanf("%c", &espe);
            //Ingreso Dni para ciclo
            printf("\n Ingrese el dni del estudiante entrevistado : ");
            scanf("%d", &dni);
        }while(n_Esc < 0 || c_Alum < 0 || (espe != 't' && espe != 'n') || dni < 1);
            //Contador especializadas
            (espe == 't')? c_T ++: c_N ++;

        //Datos de cada estudiante entrevistado
        while(dni > 0)
        {
            do{
                //Fecha de nacimiento
            printf("\n Introduzca la fecha de nacimiento (dd-mm-aaaa) :");
            scanf("%d%d%d", &ddBorn, &mmBorn, &yyBorn);
            //Sexo
            printf("\n Introduzca el sexo (M/F) :");
            fflush(stdin);
            scanf("%c", &sex);
            //Opinion
            printf("\n Intoduzca la opinion del alumno (B/M): ");
            fflush(stdin);
            scanf("%c", &opi);
            }while((ddBorn < 1 || ddBorn > 31) || (mmBorn < 1 || mmBorn > 12) || yyBorn < 1900 || (opi != 'b' && opi != 'm') || (sex != 'm' && sex != 'f'));

            //Determinar edad actual de cada estudiante
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

            //Comparador mayor edad
            if(yyEdad >= yyMax && mmEdad >= mmMax && ddEdad >= ddMax)
            {
                yyMax = yyEdad;
                mmMax = mmEdad;
                ddMax = ddEdad;
            }
            //Contador opiniones
            (opi == 'b')? cont_Buen ++: cont_Mal ++;
            //Contador femeninos
            if(sex == 'f')
                cont_F ++;
            //Contador alumnos
            cont_Al ++;
            //Ingresa nuevo Dni o finaliza con 0
            printf("\n Ingrese el DNI del proximo alumno o '0' para finalizar : ");
            scanf("%d", &dni);

        }
        //Mayor opiniones buenas
            if(cont_Buen > cont_Buen_Max)
            {
                cont_Buen_Max = cont_Buen;
                n_Esc_Buen = n_Esc;
            }
        //Total de encuestados
        if(cont_Al > 0)
            cont_tot += cont_Al;
        //A- Porcentaje de alumnos encuestados sobre los inscriptos por colegio.
        if(cont_Al > 0)
            porcent_enc = ((cont_Al *100) / c_Alum);
        printf("\n A - El porcentaje de alumnos encuestados en esta escuela fue del %.2f porciento.", porcent_enc);
        //B- Cantidad de no tecnicos que respondieron.
        if(espe == 'n')
            cont_Al_N += cont_Al;
        //C.1- Mujeres Tecnicas que respondieron
        if(espe == 't')
            cont_F_T += cont_F;
        //D- Porcentaje que dijo que era malo sobre el total
        if(cont_Mal > 0)
            cont_Mal_Tot += cont_Mal;
    }
    //B- respuesta
    printf("\n B - La cantidad de alumnos de escuelas no tecnicas que respondieron fue de : %d", cont_Al_N);

    //C- Porcentaje de M de T sobre total de encuestados
    if(cont_F_T > 0)
        porcent_M_T_Enc = cont_F_T / cont_tot * 100;

    printf("\n C - El porcentaje de mujeres en escuelas tecnicas que respondieron la encuesta fue del %.2f porciento. ", porcent_M_T_Enc);

    //D- respuesta
    if(cont_Mal_Tot > 0)
        porcent_Mal = cont_Mal_Tot / cont_tot * 100;

    printf("\n D - El porcentaje de alumnos que respondio que la educacion era mala fue del %.2f porciento.", porcent_Mal);

    //E- Mayor edad
    printf("\n E - El alumno de mayor edad entrevistado tenia %d anos, %d meses y %d dias .", yyMax, mmMax, ddMax);

    //F- Numero de la escuela con mayor cantidad de votos positivos
    printf("\n F - La escuela con mayor cantidad de buenas opiniones sobre la calidad de edudacion es la numero : %d \n",n_Esc_Buen);

    system("pause");
    return 0;
}

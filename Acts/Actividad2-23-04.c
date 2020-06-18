//Descompone fecha

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int fecha, dd, mm, yy, mes;

    //El usuario ingresa la fecha en 8 digitos
    printf("Ingrese la fecha con el formato ddmmaaaa : ");
    scanf("%d", &fecha);

    //Descomposicion
    dd = fecha / 1000000;
    mm = fecha % 1000000 / 10000;
    yy = fecha % 10000;

    //Selector de meses
    switch(mm)
    {
        case 1 : mes = "Enero";
        break;
        case 2 : mes = "Febrero";
        break;
        case 3 : mes = "Marzo";
        break;
        case 4 : mes = "Abril";
        break;
        case 5 : mes = "Mayo";
        break;
        case 6 : mes = "Junio";
        break;
        case 7 : mes = "Julio";
        break;
        case 8 : mes = "Agosto";
        break;
        case 9 : mes = "Septiembre";
        break;
        case 10 : mes = "Octubre";
        break;
        case 11 : mes = "Noviembre";
        break;
        case 12 : mes = "Diciembre";
        break;
    }

    //Respuesta al usuario
    printf("\n La fecha es %d de %s del %d  \n", dd, mes, yy);

    system("pause");
    return 0;
}

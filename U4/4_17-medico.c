//Ejercicio 4_17
//pago medico

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int importe, histo;
    char codigo;

    //el usuario ingresa el numero de historia clinica y el codigo
    printf("\n Ingrese el numero de historia clinica : ");
    scanf("%d", &histo);
    printf("\n Ingrese el codigo : ");
    fflush(stdin);
    scanf("%c", &codigo);

    switch (codigo)
    {
        case 'A' : importe = 20;
        break;
        case 'D' : importe = 40;
        break;
        case 'F' : importe = 60;
        break;
        case 'M' : importe = 150;
        break;
        case 'T' : importe = 150;
        break;
    }

    //mensaje final con resultado

    printf("\n Numero de historia clinica %d : %c \n IMPORTE : %d \n", histo, codigo, importe);

    system("pause");
    return 0;
}

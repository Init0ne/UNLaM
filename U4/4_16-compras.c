//Ejercicio 4_16
//Compras con codigo

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cod, cant;
    float precioTotal;

    //el usuario ingresa el numero de articulo y la cantidad
    printf("\n Ingrese el codigo del articulo : ");
    scanf("%d", &cod);
    printf("\n Ingrese la cantidad : ");
    scanf("%d", &cant);

    switch (cod)
    {
        case 1 :
        case 10 :
        case 100 : precioTotal = cant * 10;
        break;
        case 2 :
        case 22 :
        case 222 : precioTotal = cant * 7;
        break;
        case 3 :
        case 33 : if (cant > 10)
                    {
                        precioTotal = cant * 3 - ((cant * 3) * 10 /100);
                    }
                    else
                    {
                        precioTotal = cant * 3;
                    }
        break;
        case 4 :
        case 44 : precioTotal = cant;
        break;
    }

    //mensaje final con resultado

    printf("\n ARTÍCULO %d CANTIDAD %d IMPORTE A PAGAR $ %.2f \n", cod, cant, precioTotal);

    system("pause");
    return 0;
}

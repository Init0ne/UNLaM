//Actividad clase 30-04 "For"  ***** Mathias Falvo

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, cont = 1, max = 0, i, posMax = 0, contPar = 0, contMulti = 0, multi = 1;

    printf("\n Ingrese un valor entero : ");
    scanf("%d", &n1);

    //Si es mayor termina el programa
    if(n1 > 20)
    {
        printf("\n Valor superior a 20 elementos. \n");
    }
    //Si no ingresa n1 numeros
    else
    {
        for(i = 0; i < n1; i++)
        {
            //Introduce nuevos valores
            printf("\n Introduzca un nuevo valor : ");
            scanf("%d", &n2);
            //Cuenta el total de valores
            cont ++;
            //Mayor valor
            if(n2 > max)
            {
                max = n2;
                posMax = cont;
            }
            //Cantidad de pares
            if(n2 % 2 == 0)
            {
                contPar ++;
            }
            //Producto divisibles por 6
            if(n2 % 6 == 0)
            {
                multi *= n2;
                contMulti ++;
            }
        }
        //Retorno al usuario
        if(contMulti == 0)
        {
            printf("\n No hubo multiplos de 6 .\n");
        }
        else
        {
            printf("\n El producto de valores multiplos de 6 es de %d. \n", multi);
        }
        printf("\n El valor mas grande fue %d, en la posicion numero %d \n", max, posMax);
        printf("\n La cantidad de valores pares ingresados fue de %d\n", contPar);
    }


    system("pause");
    return 0;
}

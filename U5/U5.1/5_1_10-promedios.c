//Promedios

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, cont0 = 0, contPos = 0, contNeg = 0, sumaPos = 0, sumaNeg = 0, i;
    float promPos = 0, promNeg = 0;

    //El usuario ingresa el numero
    printf("\n Ingrese un numero menor a 12 : ");
    scanf("%d", &n1);
    //Corrobora que el numero sea correcto
    if(n1 > 12 || n1 <= 0)
    {
        if(n1 > 12)
        {
            printf("\n Valor excedido .\n");
        }
        else
        {
            printf("\n Valor invalido. \n");
        }
    }
    else
    {
        //Procede a ingresar los numeros
        printf("\ Ingrese los %d numeros a continuacion :", n1);
        for(i = 0; i < n1; i++)
        {
            printf("\n Ingrese el numero : ");
            scanf("%d", &n2);
            //Cuenta los ceros
            if(n2 == 0)
            {
                cont0 ++;
            }
            else
            {
                //Suma y cuenta positivos y negativos
                if(n2 > 0)
                {
                    sumaPos += n2;
                    contPos ++;
                }
                else
                {
                    sumaNeg += n2;
                    contNeg ++;
                }
            }
        }
        //Promedia
        if(contPos > 0)
        {
            promPos = sumaPos / contPos;
        }
        if(contNeg > 0)
        {
            promNeg = sumaNeg / contNeg;
        }

        printf("\n La cantidad de ceros fue de %d, el promedio de los positivos %.2f y el promedio de los negativos %.2f \n", cont0, promPos, promNeg);
    }

    system("pause");
    return 0;
}

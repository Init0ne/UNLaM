//Programa que calcula el numero mayor o menor de una terna

#include <stdio.h>
#include <stdlib.h>

int MayorMenor (int,int,int);

int main()
{
    int n1, n2, n3;

    do{
        printf("\n Ingrese el primer numero de la terna (entre 0 y 99) : ");
        scanf("%d", &n1);
        printf("\n Ingrese el segundo numero de la terna (entre 0 y 99) : ");
        scanf("%d", &n2);
        printf("\n Ingrese el tercer numero de la terna (entre 0 y 99) : ");
        scanf("%d", &n3);
    } while (n1 < 0 && n1 > 99 || n2 < 0 && n2 > 99 || n3 < 0 && n3 > 99);

    while (n1 != 96 && n2 != 97 && n3 != 98)
    {
        MayorMenor(n1,n2,n3);

        do{
            printf("\n Ingrese el primer numero de la terna (entre 0 y 99) o 96,97,98 para finalizar : ");
            scanf("%d", &n1);
            printf("\n Ingrese el segundo numero de la terna (entre 0 y 99) o 96,97,98 para finalizar : ");
            scanf("%d", &n2);
            printf("\n Ingrese el tercer numero de la terna (entre 0 y 99) o 96,97,98 para finalizar : ");
            scanf("%d", &n3);
        } while (n1 < 0 && n1 > 99 || n2 < 0 && n2 > 99 || n3 < 0 && n3 > 99);
    }

    system("pause");
    return 0;
}

int MayorMenor(int n1, int n2, int n3)
{
    int flagM, mayor, menor;

    //Seleccion Mayor o menor
    printf("\n Si desea encontrar el MAYOR numero de la terna ingrese 1 de lo contrario ingrese 0 : ");
    scanf("%d", &flagM);

    if (flagM == 1)
    {
        if (n1 > n2)
        {
            if (n1 > n3)
            {
                mayor = n1;
            }
            else
            {
                mayor = n3;
            }
        }
        else
        {
            if (n2 > n3)
            {
                mayor = n2;
            }
            else
            {
                mayor = n3;
            }
        }
        printf("\n El numero mayor de la terna es : %d", mayor);
    }
    else
    {
        if(n1 < n2)
        {
            if(n1 < n3)
            {
                menor = n1;
            }
            else
            {
                menor = n3;
            }
            
        }
        else
        {
            if(n2 < n3)
            {
                menor = n2;
            }
            else
            {
                menor = n3;
            }
            
        }
        printf("\n El numero menor de la terna es : %d", menor);
    }
    return 0;
}
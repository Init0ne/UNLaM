//lee valida, y cuenta numeros en un rango

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, contMen, contPar, suma, contSuma;
    float promedio;

    n = LeerYValidar();

    while(n != 99)
    {
        contSuma = 0; contMen = 0; contPar = 0; suma = 0;

        if(n < 500)
        {
            contMen ++;
        }
        else
        {
            if(n < 1200)
            {
                if (n % 2 == 0)
                {
                    contPar ++;
                }
            }
            else
            {
                suma += n;
                contSuma;
            }
            
        }
    n = LeerYValidar();
    }

    promedio = (float)suma / contSuma;
    
    printf("\n A - La cantidad de numeros ingresados entre 100 y 500 es de : %d", contMen);
    printf("\n B - La cantidad de numeros pares ingresados entre 500 y 1200 es de : %d", contPar);
    printf("\n C- El promedio de numeros ingresados entre 1200 y 2000 es de : %.2f", promedio);

    system("pause");
    return 0;
}

int LeerYValidar(void)
{
    int n, flag;
    do{
        printf("\n Ingrese un numero entre 100 y 2000, o 99 para salir : ");
        scanf("%d", &n);
        flag = EstaDentroDelRango(n);
    }while(flag = 0);
}

int EstaDentroDelRango(int n)
{
    int flag;
    if(n < 99 || n > 2000)
    {
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    return flag;
}
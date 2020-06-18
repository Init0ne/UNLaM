//Control de variable N

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n1, n2, i, sumaMultiTres = 0, cantMultiCinco = 0, sumaPares = 0;

    //El usuario ingresa el numero N
    printf("\n Ingrese un numero : ");
    scanf("%d", &n1);

    for(i = 0; i < n1; i++)
    {
        //El usuario ingresa N cantidad de numeros
        printf("\n Ingrese un nuevo numero :");
        scanf("%d", &n2);

        //Sumatoria multiplos de 3
        if(n2 % 3 == 0)
        {
            sumaMultiTres += n2;
        }
        if(n2 % 5 == 0)
        {
            cantMultiCinco ++;
        }
        if(n2 % 2 == 0)
        {
            sumaPares += n2;
        }
    }
    printf("\n La sumatoria de los valores multiplos de 3 es %d \n", sumaMultiTres);
    printf("\n La cantidad de valores multiplos de 5 es %d \n", cantMultiCinco);
    printf("\n La sumatoria de los valores de orden par es %d \n", sumaPares);


    system("pause");
    return 0;
}

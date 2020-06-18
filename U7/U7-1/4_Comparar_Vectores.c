/*
7.1.4 Construir una función que reciba dos vectores enteros de igual tamaño
y retorne un 1 si son guales o un 0 sino lo son.
*/ 

#include <stdio.h>
#include <stdlib.h>

void carga(int[], int);
int compara_Vectores(int[], int[]);

int main()
{
    int v1[5], v2[5], flag;

    carga(v1,5);
    printf("\n Proximo vector \n");
    carga(v2,5);

    flag = compara_Vectores(v1,v2);
    
    if(flag != 0)
    {
        printf("\n Los vectores son iguales !!\n");
    }
    else
    {   
        printf("\n Los vectores son diferentes !!\n");
    }

    system("pause");
    return 0;
}

void carga(int v[],int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\n Ingrese un nuero entero : ");
        scanf("%d", &v[i]);
    }
}

int compara_Vectores(int v1[], int v2[])
{
    int i, flag = 1;
    
    do
    {
        for(i = 0; i < 5; i++)
        {
            
            if(v1[i] == v2[i])
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }   
        }
    }while(flag == 1 && i < 5);

    return flag;
}
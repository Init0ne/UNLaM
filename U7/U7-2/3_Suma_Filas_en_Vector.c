/*
7.2.3 Ingresar una matriz de 5x4 por teclado. 
Realizar una función que genere un vector con la suma por fila de dicha matriz. 
*/

#include<stdio.h>
#include<stdlib.h>

void carga_Matriz(int[][4]);
void suma_Filas(int[][4], int[]);
void informar_MatrizInicial(int[][4]);

int main()
{
    int m_Inicial[5][4], v_Sumas[5], k;

    carga_Matriz(m_Inicial);
    system("cls");
    informar_MatrizInicial(m_Inicial);

    printf("\n\n");

    suma_Filas(m_Inicial,v_Sumas);
    
    for(k = 0; k < 5; k++)
    {
        printf("\n La suma de la fila %d es = %d \n", k,v_Sumas[k]);
    }

    system("pause");
    return 0;
}

void carga_Matriz(int m_Inicial[][4])
{
    int i,j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("\n Ingrese el valor de la posicion (%d;%d) :", i,j);
            scanf("%d", &m_Inicial[i][j]);
        }
    }
}

void suma_Filas(int m_Inicial[][4], int v_Sumas[])
{
    int i, j, suma;
    
    for(i = 0; i < 5; i++)
    {
        suma = 0;
        for(j = 0; j < 4; j++)
        {
            suma += m_Inicial[i][j];
        }
        v_Sumas[i] = suma;
    }
}

void informar_MatrizInicial(int m_Inicial[][4])
{
    int i,j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%4d", m_Inicial[i][j]);
        }
        printf("\n");
    }
}


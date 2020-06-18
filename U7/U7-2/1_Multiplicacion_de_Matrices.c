/*
7.2.1 Ingresar  una  matriz  de  3x3  por  teclado  y  un  número  entero.  
Realizar  el  producto  de  la matriz  por  la constante.
*/

#include<stdio.h>
#include<stdlib.h>

void carga_Matriz(int[][3]);
void multiplicar_Matriz(int[][3],int,int[][3]);
void mostrar_MatrizFinal(int[][3]);

int main()
{
    int n, m_Inicial[3][3], m_Final[3][3];

    carga_Matriz(m_Inicial);
    
    printf("\n Ingrese el numero por el cual va a multiplicar la matriz :");
    scanf("%d", &n);

    multiplicar_Matriz(m_Inicial, n, m_Final);

    mostrar_MatrizFinal(m_Final);

    system("pause");
    return 0;
}

void carga_Matriz(int m_Inicial[][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("\n Ingresar el valor del indice (%d,%d) :", i,j);
            scanf("%d", &m_Inicial[i][j]);
        }
    }
}

void multiplicar_Matriz(int m_Inicial[][3], int n, int m_Final[][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            m_Final[i][j] = m_Inicial[i][j] * n;
        }
    }
}

void mostrar_MatrizFinal(int m_Final[][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf(" %d \t", m_Final[i][j]);
        }
        printf("\n");
    }
}
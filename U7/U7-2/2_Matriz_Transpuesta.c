/*
7.2.2 Ingresar una matriz de 2x3 por teclado. Calcular la matriz transpuesta.
*/

#include<stdio.h>
#include<stdlib.h>

void carga_Matriz(int[][3]);
void informar_MatrizTranspuesta(int[][3], int[][2]);
void informar_MatrizInicial(int [][3]);

int main()
{
    int m_Inicial[2][3], m_Transpuesta[3][2];

    //Carga e informa matriz inicial
    carga_Matriz(m_Inicial);

    system("cls");

    informar_MatrizInicial(m_Inicial);
    //Separacion entre matrices
    printf("\n\n");
    //Asigna e informa la transpuesta
    informar_MatrizTranspuesta(m_Inicial,m_Transpuesta);

    system("pause");
    return 0;
}

void carga_Matriz(int m_Inicial[][3])
{
    int i,j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("\n Ingrese el valor de la posicion (%d;%d) :", i,j);
            scanf("%d", &m_Inicial[i][j]);
        }
    }
}

void informar_MatrizTranspuesta(int m_Inicial[][3], int m_Transpuesta[][2])
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 2; j++)
        {
            m_Transpuesta[i][j] = m_Inicial[j][i];
            printf("%4d", m_Transpuesta[i][j]);
        }
        printf("\n");
    }
}

void informar_MatrizInicial(int m_Inicial[][3])
{
    int i,j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%4d", m_Inicial[i][j]);
        }
        printf("\n");
    }
}
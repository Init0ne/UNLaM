#include <stdio.h>
#include <stdlib.h>
void mostrar(int[][3]);
void moverNumero(int[][3], int, int);
int comprobarEstado(int[][3]);
int main()
{
	int f, c;
	int m[3][3]={2,5,1,7,6,3,8,0,4}; //matriz de prueba mÃ¡s desordenada
	//int m[3][3]={1,2,3,4,5,6,7,0,8};  //matriz de prueba practicamente ordenada
	int gano=0,num,encontrado;
    int i, j;

	while (!gano)
	{
		mostrar(m);		
		do 
		{
			printf("\nIngrese el numero que desea mover:");
			scanf("%d",&num);
		}while (num<1||num>8);
										
		encontrado=0;
		f=0;c=0;											
		while (!encontrado)
		{
			/*COMPLETAR
			realizar un algoritmo que busque en la matriz en numero ingresado	
			y que se encuentra en la variable num
			El algoritmo debe finalizar en el momento que encuentra el nÃºmero y 
			completar las variables f y c con la fila y columna donde lo encontrÃ³
			*/
            while(encontrado == 0 && c < 3 )
            {
                if(m[f][c] == num)
                {
                    encontrado = 1;
                }
                else
                {
                    c++;
                }
            }
            if(encontrado == 0)
            {
                c = 0;
                f++;
            }
        }
		
		moverNumero(m,f,c);
		gano = comprobarEstado (m);
	}
		
	mostrar(m);		
	printf("\n\nFELICIDADES GANO!!!\n\n");
	system("pause");
	return 0;
}

void moverNumero(int m[][3], int f, int c)
{
	int movimiento=0;	
	int num= m[f][c];

    int aux;
	
	/*COMPLETAR
	La funcion recibe la fila y columna de la matriz donde estÃ¡ el numero que
	se desea mover. Se debe realizar el algoritmo para que lo mueva al casillero
	adyacente que este libre, es decir que tenga un 0.
	Tener en cuenta que no siempre se puede mover solo lo debe mover si el 0 estÃ¡
	en una de cuatro posiciones en la celda de arriba, de abajo de la derecha o 
	izquierda sino no hace nada.
	Tambien considerar que no siempre estÃ¡n las 4 opciones ya que el numero a mover
	puede estar en alguno de los extremos de la matriz
	
	Ayuda puede resolverse con 4 if anidados (arriba,abajo, izquierda y derecha  de
	la celda recibida por parÃ¡metro)
	*/
		
    if(f - 1 >= 0 && m[f-1][c] == 0)
    {
        aux = m[f-1][c];
        m[f-1][c] = num;
        m[f][c] = aux;
    }
    else
    {
        if(f + 1 < 3 && m[f+1][c] == 0)
        {
            aux = m[f+1][c];
            m[f+1][c] = num;
            m[f][c] = aux;
        }
        else
        {
            if(c - 1 >= 0 && m[f][c-1] == 0)
            {
                aux = m[f][c-1];
                m[f][c-1] = num;
                m[f][c] = aux;
            }
            else
            {
                if(c + 1 < 3 && m[f][c+1] == 0)
                {
                aux = m[f][c+1];
                m[f][c+1] = num;
                m[f][c] = aux;
                }
            }
            
        }
        
    }
    
}

void mostrar(int m[][3])
{
	system("cls");
	/*COMPLETAR
	Mostrar la matriz pero teniendo en cuenta que el 0 no debe mostrarse
	cuando el valor sea 0 se debe mostrar un espacio en blanco
	*/
    int i,j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(m[i][j] != 0)
            {
                printf("%d ",m[i][j]);
            }
            else
            {
                printf("  ");
            }
        }
    printf("\n");
    }
}

int comprobarEstado(int m[][3])
{
	int gano;
	/*COMPLETAR
	Si la matriz quedÃ³ ordenada en la variable gano debe quedar un 1 sino un 0.
	Para que estÃ© ordenada la matriz debe estar de la siguiente forma:
	1 2 3
	4 5 6
	7 8 0
	*/
	int i, j, m_Ganar [3][3] = {1,2,3,4,5,6,7,8,0};

    gano = 1;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(m[i][j] != m_Ganar[i][j])
            {
                gano = 0;
            }
        }
    }

	return gano;
}
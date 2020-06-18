/*
7.1.6 Idem ejercicio  anterior,  pero  con  código  de  productos  no  correlativos  de  4  dígitos. 
Los  códigos  deben solicitarse al iniciar el programa mediante la función IngresaCodigos. 
Luego de la carga determinar:
a.El / los productos del cual se solicitaron mayor cantidad de unidades.
b.El / los productos del cual se solicitaron menos cantidad de unidades.
*/

#include <stdio.h>
#include <stdlib.h>

int ingreso_Codigo(void);
void mostrar_Vectores(int[], int[], int);

int main()
{
    int v_Cod[10], v_Cant[10], i, max_C, min_C, pos_Max, pos_Min;

    i = 0, max_C = 0, min_C = 0;
    //Carga datos y finaliza en 0
    do
    {
        //Ingresa el codigo
        v_Cod[i] = ingreso_Codigo();

        //Ingresa la cantidad por producto
        if(v_Cod[i] !=0)
        {
            printf("\n Ingrese la cantidad de unidades deseadas : ");
            scanf("%d", &v_Cant[i]);
            //Compara las cantidades
            if(v_Cant[i] > max_C)
            {
                max_C = v_Cant[i];
                pos_Max = i;
            }
            else
            {
                if(v_Cant[i] < min_C)
                {
                    min_C = v_Cant[i];
                    pos_Min = i;
                }
            }
        }
        //Incrementa el puntero del vector
        i++;
    } while (v_Cod[i - 1] != 0 && i < 10);
    
    mostrar_Vectores(v_Cod, v_Cant, i);

    printf("\n El producto mas pedido fue el cod : %d con un total de %d unidades!\n", v_Cod[pos_Max], max_C);
    printf("\n El producto menos pedido fue el cod : %d con un total de %d unidades!\n", v_Cod[pos_Min], min_C);
    
    system("pause");
    return 0;
}

//Funcion para ingresar el codigo y validarlo
int ingreso_Codigo (void)
{
    int cod;
    do
    {
        printf("\n Ingrese el codigo del producto :");
        scanf("%d", &cod);
    } while (cod < 0 || cod > 9999);
}

//Funcion para mostrar resumen de compras del dia
void mostrar_Vectores(int v[], int v1[],int i)
{
    int k;
    printf("\n ----------------------------------------------- \n");
    printf("\n \tCodigo \t\t Cantidad \n");
    for(k = 0; k < i; k++)
    {
        printf("\n \t%d \t\t %d \n", v[k], v1[k]);
    }
    printf("\n ----------------------------------------------- \n");
}
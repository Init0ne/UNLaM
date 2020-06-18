/*
7.1.5 
Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. 
Por cada pedido se recibe:
• Código de producto (de 1 a 10)
• Cantidad de unidades solicitadas 
Se puede recibir más de un pedido por producto. 
La carga finaliza cuando se ingresa un producto con código igual a cero. 
Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto. 
*/

#include <stdio.h>
#include <stdlib.h>

void carga(int[]);
void mostrar_Resumen(int[]);

int main()
{
    int v_Cod[10];

    carga(v_Cod);
    mostrar_Resumen(v_Cod);

    system("pause");
    return 0;
}

void carga(int v[])
{
    int cod, cant;
    do
    {
        // El usuario ingresa el codigo del producto
        do
        {
            printf("\n Ingrese el codigo del producto (o '0' para finalizar): ");
            scanf("%d", &cod);
        }while(cod > 10 || cod < 0);
            //El usuario ingresa la cantidad de cada producto
            if(cod != 0)
            {
                printf("\n Ingrese la cantidad de unidades :");
                scanf("%d", &cant);
                v[cod - 1] += cant;
            }
            else
            {
                printf("\n Gracias por su compra ! \n");
            }
    } while (cod != 0);
}

void mostrar_Resumen(int v[])
{
    int i;

    printf("\n Resumen del dia \n");
    printf("\n\n ----------------------------------------------- \n\n");
    for(i = 0; i < 10; i++ )
    {
        printf("\n Cod : %d \t\t Cantidad : %d \n", i+1, v[i]);
    }
    printf("\n\n ----------------------------------------------- \n\n");
}
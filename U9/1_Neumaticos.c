#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char codigo[6];
    float precio;
    char descri[31];
    int cant;
    float importe;
}producto;

void leer_Texto(char [], int );
int cargar_Productos(producto []);
void ventas_Mes(producto [], int );

int main()
{
    producto prod[50];
    int cant_Productos,i;

    printf("\n Cargue la informacion de los productos a continuacion . \n");
    cant_Productos = cargar_Productos(prod);
    system("cls");

    printf("\n Ingrese los nuevos pedidos ! \n");
    ventas_Mes(prod,cant_Productos);
    system("cls");

    //A- Actualizar importe total por producto
    for(i = 0; i < cant_Productos; i++)
    {
        prod[i].importe = (float)prod[i].cant * prod[i].precio;
    }

    //B- Informe listado de productos actualizado
    printf("\n \t\tDESCRIPCION \t\t\t\t CANTIDAD DE UNIDADES \t\t\t    IMPORTE TOTAL");
    printf("\n  \t\t\t\t\t\t\t\t VENDIDAS \t\t\t\t VENDIDO\n");
    
    for(i = 0; i < cant_Productos; i++)
    {
        printf("\n %30s \t\t\t %15d \t\t\t\t $%8.2f",prod[i].descri,prod[i].cant,prod[i].importe);
    }
    printf("\n\n");

    system("pause");
    return 0;
}

void leer_Texto(char texto[], int largo)
{   
    int i = 0;
    fflush(stdin);
    fgets(texto,largo,stdin);

    while(texto[i] != '\0')
    {
        if(texto[i] == '\n')
        {
            texto[i] = '\0';
        }
        else
        {
            i++;
        }
    }
}

int cargar_Productos(producto prod[])
{
    int  i;
    char codAux[6], descriAux[31];
    float precioAux;

    i = 0;

    printf("\n Ingrese el codigo del producto : ");
    leer_Texto(codAux,6);
    
    printf("\n Ingrese el precio del producto : ");
    fflush(stdin);
    scanf("%f", &precioAux);

    printf("\n Ingrese la descripcion del producto : ");
    leer_Texto(descriAux,31);

    while(i < 51 && (strcmpi(descriAux,"FIN") != 0) )
    {
        if((strcmpi(descriAux,"FIN") != 0))
        {
            printf("\n Ingrese la cantidad de unidades vendidas (del mes anterior) : ");
            fflush(stdin);
            scanf("%d", &prod[i].cant);

            strcpy(prod[i].codigo,codAux);
            prod[i].precio = precioAux;
            strcpy(prod[i].descri,descriAux);
            prod[i].importe = (float)prod[i].cant * prod[i].precio;

            i++;
        }

        printf("\n Ingrese el codigo del producto : ");
        leer_Texto(codAux,6);
        
        printf("\n Ingrese el precio del producto : ");
        fflush(stdin);
        scanf("%f", &precioAux);

        printf("\n Ingrese la descripcion del producto : ");
        leer_Texto(descriAux,31);
    } 
    return i;
}

void ventas_Mes(producto prod[], int cant_Productos)
{
    int i, cant_Pedida = 1, indice, cant_Anterior;
    char codAux[6];

    while(cant_Pedida != 0)
    {
        printf("\n Ingrese el codigo del producto :");
        leer_Texto(codAux,6);

        for(i = 0; i < cant_Productos; i++)
        {
            if((strcmpi(codAux,prod[i].codigo) == 0))
            {
                indice = i;
            }
        }

        printf("\n Ingrese la cantidad pedida : ");
        fflush(stdin);
        scanf("%d", &cant_Pedida);

        if(cant_Pedida != 0)
        {
            prod[indice].cant += cant_Pedida;
        }
    }
}


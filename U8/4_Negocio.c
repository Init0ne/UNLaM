/*
8.4
Se ingresan código y precio unitario de los productos que vende un negocio. 
No se sabe la cantidad exacta de productos, pero sí se sabe que son menos de 50. 
El código es alfanumérico de 3 caracteres y la carga de los datos de productos termina con un código igual al “FIN”. 
Luego se registran las ventas del día y por cada venta se ingresa el código de producto y cantidad de unidades vendidas,
terminando con una cantidad igual a 0. 
Se solicita:
a.Calcular la recaudación total del día y el producto del cual se vendió menor cantidad deunidades.
b.Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void leer_Texto(char [], int );
int ingreso_Datos(char [][4], float []);
void carga_Ventas(char [][4], int [], int );
void menos_Vendido(int [], int [], int );
void ordenar_Productos(char [][4], int );

int main()
{
    int cant_Unidades[50] = {0}, pos_menosVendidos [50] = {0}, cant_Productos, i;
    float precio[50], recaudacion_Tot;
    char cod[50][4];

    cant_Productos = ingreso_Datos(cod,precio);

    printf("\n\t\tCarga de ventas \n");

    carga_Ventas(cod,cant_Unidades,cant_Productos);

    //a.Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
    recaudacion_Tot = 0;
    for(i = 0; i <= cant_Productos; i++)
    {
        recaudacion_Tot += precio[i] * (float)cant_Unidades[i];
    }
    menos_Vendido(cant_Unidades,pos_menosVendidos,cant_Productos);

    printf("\n Recaudacion total del dia : %.2f \n", recaudacion_Tot);
    printf("\n El/Los productos menos vendidos fueron : \n");
    //Muestra codigo de los productos menos vendidos
    for(i = 0; i < cant_Productos; i++)
    {
        if(pos_menosVendidos[i] == 1)
        {
            puts(cod[i]);
        }
    }
    //b.Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.

    ordenar_Productos(cod,cant_Productos);
    //Muestra producto y precio
    printf("\n Producto \t\t Precio\n");
    for(i = 0; i < cant_Productos; i++)
    {
        printf("\n %4s \t\t %.2f\n", cod[i], precio[i]);
    }

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

void todo_Mayusculas(char texto[])
{
    int i,largo;

    largo = strlen(texto);    
    for(i = 0; i <= largo; i++)
    {
        texto[i] = toupper(texto[i]);
    }
}

int ingreso_Datos(char cod[][4], float precio[])
{
    int i = 0;
    char cod_Aux[4];

    printf("\n Ingrese el codigo del producto a continuacion:");
    leer_Texto(cod_Aux,4);
    todo_Mayusculas(cod_Aux);

    while((strcmp(cod_Aux,"FIN") != 0))
    {
        printf("\n Ingrese el precio del producto : ");
        fflush(stdin);
        scanf("%f", &precio[i]);

        strcpy(cod[i],cod_Aux);
        i++;

        printf("\n Ingrese el codigo del proximo producto (o 'FIN' para terminar):");
        leer_Texto(cod_Aux,4);
        todo_Mayusculas(cod_Aux);
    }
    return i;
}

void carga_Ventas(char cod[][4], int cant_Unidades[], int cant_Productos)
{
    int j, indice, unidades = 1;
    char cod_Aux[4];

    while(unidades != 0)
    {
        printf("\n Ingrese el codigo del producto :");
        leer_Texto(cod_Aux,4);
        todo_Mayusculas(cod_Aux);

        j = 0;
        indice = -1;

        while (indice == -1 && j <= cant_Productos)
        {
            if(strcmp(cod_Aux,cod[j]) == 0)
            {
                indice = j;
            }
            else
            {
                j++;
            }
        }

        printf("\n Ingrese la cantidad de unidades vendidas (o 0 para finalizar) : ");
        scanf("%d", &unidades);
        if(unidades > 0)
        {
            cant_Unidades[indice] = unidades;
        }
    }
}

void menos_Vendido(int cant_Unidades[], int pos_MenosVendidos[], int cant_Productos)
{
    int i, menos_Vendido;

    menos_Vendido = cant_Unidades[0];
    for(i = 0; i < cant_Productos; i++)
    {
        if(cant_Unidades[i] < menos_Vendido)
        {
            menos_Vendido = cant_Unidades[i];
            pos_MenosVendidos[i] = 1;
        }
    }
    for(i = 0; i < cant_Productos; i++)
    {
        if(cant_Unidades[i] == menos_Vendido)
        {
            pos_MenosVendidos[i] = 1;
        }
    }
}

void ordenar_Productos(char cod[][4], int cant_Productos)
{
    int j, desordenado = 1, cota = (cant_Productos - 1);
    char aux[4];

    while(desordenado != 0)
    {
        desordenado = 0;

        for(j = 0; j < cota; j++)
        {
            if(strncmp(cod[j], cod[j+1], 1) > 0)
            {
                strcpy(aux,cod[j]);
                strcpy(cod[j],cod[j+1]);
                strcpy(cod[j+1],aux);

                desordenado = j;
            }
        }

        cota = desordenado;
    }
}
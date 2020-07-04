#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char Sucursal[15];
    int CodigoDeProducto;
    int Cantidad;
}ventas;

typedef struct 
{
    int CodigoDeProducto;
    char Descripcion[20];
    float Precio;
    int Stock;
    int PuntoDePedido;
    int CantidadPedida;
}productos;

typedef struct 
{
    int CodigoDeProducto;
    int CantidadPedida;
}pedidos;

void readFilesV(ventas );

int main()
{
    ventas ventas;
    readFilesV(ventas);

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

void readFilesV(ventas estru)
{
    FILE *arch;
    arch = fopen("ventas.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&estru, sizeof(estru), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n \tSucursal \t\t\t Codigo \t\t\t Cantidad");
    while(!feof(arch))
    {
        printf("\n %15s |\t %d |\t %d", estru.Sucursal, estru.CodigoDeProducto, estru.Cantidad );
        fread(&estru, sizeof(estru), 1, arch);
    }
    printf("\n");
    fclose(arch);
}

/*
void readFilesPr(productos estru)
{
    FILE *arch;
    arch = fopen("productos.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&estru, sizeof(estru), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n Codigo \t Precio \t Desscripcion");
    while(!feof(arch))
    {
        printf("\n %5d \t\t $%10.2f \t %s", art.cod, art.precio, art.descri );
        fread(&art, sizeof(productos), 1, arch);
    }
    printf("\n");
    fclose(arch);
}

void readFilesPe(pedidos estru)
{
    FILE *arch;
    arch = fopen("pedidos.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&estru, sizeof(estru), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n Codigo \t Precio \t Desscripcion");
    while(!feof(arch))
    {
        printf("\n %5d \t\t $%10.2f \t %s", art.cod, art.precio, art.descri );
        fread(&art, sizeof(productos), 1, arch);
    }
    printf("\n");
    fclose(arch);
}
*/
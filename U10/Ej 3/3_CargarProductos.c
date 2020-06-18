#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int cod;
    float precio;
    char descri[50];
}productos;

void carga_productos(productos );

int main()
{
    productos prod;
    
    printf("\n Bienvenido a la carga de datos para las siguientes actividades!.\n\n\n");

    carga_productos(prod);

    printf("\n Carga realizada con exito! \n\n");

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

void carga_productos(productos prod)
{
    FILE *produ;
    produ = fopen("productos.dat", "a+b");
    //Se corrobora que el archivo exista 
    if(produ == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }

    printf("\n Ingrese el codigo del producto a cargar (0 para terminar): ");
    scanf("%d", &prod.cod);
    while(prod.cod != 0)
    {
        printf("\n Ingrese el precio del producto : $");
        scanf("%f", &prod.precio);
        printf("\n Ingrese la descripcion del producto :");
        leer_Texto(prod.descri,50);

        fwrite(&prod,sizeof(productos),1,produ);
        fflush(stdin);

        printf("\n Ingrese el codigo del producto a cargar (0 para terminar): ");
        scanf("%d", &prod.cod);
    }
    fclose(produ);
}
/*
10.4. Realizar un programa que permite actualizar una lista de precios en forma masiva, 
ingresando un porcentaje de incremento.
El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:  
• Código (entero) • Precio (float) • Descripción (de hasta 50 caracteres) 

No se sabe la cantidad de registros del archivo.   
Se solicita generar un nuevo archivo llamado Precios_actualizados.dat. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod;
    float precio;
    char descri[50];
}productos;

void generarOriginal ();
void mostrar_Archivo(productos);
void actualizarPrecios (float);

int main()
{
    generarOriginal();
    actualizarPrecios(20);

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

void generarOriginal ()
{
    productos art;
    int correcto;

    FILE *precios;

    precios = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 4\\precios.dat","a+b");
    //Se corrobora que el archivo exista 
    if(precios == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }

    printf("\n Ingrese el codigo del articulo (o 0 para terminar) :");
    scanf("%d", &art.cod);

    while(art.cod)
    {
        printf("\n Precio : $");
        scanf("%f", &art.precio);
        printf("\n Descripcion : ");
        leer_Texto(art.descri,50);

        correcto = fwrite(&art,sizeof(productos),1,precios);
        fflush(stdin);
        //printf("\n\n Escritura = %d\n\n", correcto);

        printf("\n Ingrese el codigo del articulo (o 0 para terminar) :");
        scanf("%d", &art.cod);
    }
    fclose(precios);
    mostrar_Archivo(art);
}

void mostrar_Archivo(productos art)
{
    FILE *arch;
    arch = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 4\\precios.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&art, sizeof(productos), 1, arch);
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

void actualizarPrecios (float porcent)
{
    FILE *old, *update;
    int escritura,lectura;
    productos art, art2;

    old = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 4\\precios.dat","rb");
    if(old == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    update = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 4\\Precios_actualizados.dat","wb");
    if(update == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }

    while(!feof(old))
    {
        lectura = fread(&art, sizeof(productos),1,old);
        //printf("\n\n Lectura = %d \n\n", lectura);
        if(lectura)
        {
            art2.cod = art.cod;
            art2.precio = art. precio + (art.precio * porcent / 100);
            strcpy(art2.descri,art.descri);
            fflush(stdin);
            escritura = fwrite(&art2, sizeof(productos),1,update);
            fflush(stdin);
            //printf("\n\n Escritura = %d \n\n", escritura);
        }
    }
    fclose(old);
    fclose(update);

    update = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 4\\Precios_actualizados.dat","rb");
    //Lectura archivo
    lectura = fread(&art, sizeof(productos), 1, update);
    //printf("\n\n Lectura = %d \n\n", lectura);
    //Mientras no llegue al final del archivo lee
    printf("\n Codigo \t Precio \t Desscripcion");
    while(!feof(update))
    {
        printf("\n %5d \t\t $%10.2f \t %s", art.cod, art.precio, art.descri );
        lectura = fread(&art, sizeof(productos), 1, update);
        //printf("\n\n Lectura = %d \n\n", lectura);
    }
    printf("\n");
    fclose(update);
}


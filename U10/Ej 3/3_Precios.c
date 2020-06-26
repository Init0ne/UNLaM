#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int cod;
    float precio;
    char descri[50];
}productos;

void mostrar_Archivo(productos );

int main()
{
    productos prod;
    int cod, flag, n;
    float precio;
    
    printf("\n Bienvenidos al sistema de actualizacion de precios! \n\n\n");
    printf("\n Para comenzar ingrese el codigo del producto :");
    scanf("%d", &cod);



    while (cod != 0)
    {
        printf("\n Ingrese el nuevo precio : $");
        fflush(stdin);
        scanf("%f", &precio);
        
        //Apertura del archivo
        FILE * prodFile;
        prodFile = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 3\\productos.dat","r+b");
        //Se corrobora que no haya problemas
        if(prodFile == NULL)
        {
            printf("\n Se produjo un error al abrir el archivo.");
            system("pause");
            exit(1);
        }

        flag = 0;
        while (!feof(prodFile) && flag != 1)
        {
            fread(&prod,sizeof(productos),1,prodFile);

            if(prod.cod == cod)
            {
                prod.precio = precio;
                n = fwrite(&prod,sizeof(productos),1,prodFile);
                printf("\n El precio fue actualizado satisfactoriaente! \n");
                flag = 1;
                printf("\n %d",n);
            }

        }
        if(flag == 0)
        {
            printf("\n Codigo no existente, intentelo nuevamente!\n");
        }
        fclose(prodFile);
        //Nuevo comienzo de ciclo
        printf("\n Ingrese el codigo del siguiente producto a modificar : ");
        fflush(stdin);
        scanf("%d", &cod);
    }
    
    //Pruebas
    printf("A continuacion se muestra la lista actualizada.");
    mostrar_Archivo(prod);

    system("pause");
    return 0;
}

void mostrar_Archivo(productos prod)
{
    FILE *arch;
    arch = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 3\\productos.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&prod, sizeof(productos), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n Codigo \t Precio \t Desscripcion");
    while(!feof(arch))
    {
        printf("\n %5d \t\t $%10.2f \t %s", prod.cod, prod.precio, prod.descri );
        fread(&prod, sizeof(productos), 1, arch);
    }
    printf("\n");
    fclose(arch);
}
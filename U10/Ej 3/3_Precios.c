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
    int cod, flag;
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
        FILE * produ;
        produ = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 3\\productos.dat","a+b");
        //Se corrobora que no haya problemas
        if(produ == NULL)
        {
            printf("\n Se produjo un error al abrir el archivo.");
            system("pause");
            exit(1);
        }

        flag = 0;
        while (!feof(produ) && flag != 1)
        {
            fread(&prod,sizeof(productos),1,produ);
            fflush(stdin);

            if(prod.cod == cod)
            {
                prod.cod = cod;
                prod.precio = precio;
                fwrite(&prod,sizeof(productos),1,produ);
                fflush(stdin);
                printf("\n El precio fue actualizado satisfactoriaente! \n");
                flag = 1;
            }

        }
            if(flag == 0)
            {
                printf("\n Codigo no existente, intentelo nuevamente!\n");
            }
            fclose(produ);
            //Nuevo comienzo de ciclo
            printf("\n Ingrese el codigo del siguiente producto a modificar : ");
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
    arch = fopen("productos.dat","rb");
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
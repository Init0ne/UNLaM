#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int dni;
    char nombre_Apellido[80];
    int nota[2];
    float nota_Promedio;
}alumnos;

void crear_Archivos(alumnos );
void leer_Archivos(char []);

int main()
{
    alumnos al;
    char nombre_Archivo[30];

    crear_Archivos(al);

    leer_Archivos("promocionados.dat");
    system("pause");
    leer_Archivos("cursados.dat");
    system("pause");
    leer_Archivos("reprobados.dat");
    

    system("pause");
    return 0;
}

void crear_Archivos(alumnos al)
{
    //Crea los punteros de cada archivo
    FILE *alum, *promo, *cur, *rep ;
    //Abre y lee el archivo alumnos.dat
    alum = fopen("alumnos.dat","rb");
    fread(&al, sizeof(alumnos), 1, alum);
    //Abre los nuevos archivos
    promo = fopen("promocionados.dat","wb");
    cur = fopen("cursados.dat","wb");
    rep = fopen("reprobados.dat","wb");

    if(al.nota[0] < 4 || al.nota[1] < 4)
    {
        fwrite(&al, sizeof(alumnos), 1, rep);
    }
    else
    {
        if(al.nota[0] < 7 || al.nota[1] < 7)
        {
            fwrite(&al, sizeof(alumnos), 1, cur);
        }
        else
        {
            fwrite(&al, sizeof(alumnos), 1, promo);
        }
    }
    fclose(alum);
    fclose(rep);
    fclose(cur);
    fclose(promo);
}

void leer_Archivos(char nombre_Archivo[])
{
    alumnos aux;
    FILE *arch;
    arch = fopen(nombre_Archivo,"rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&aux, sizeof(alumnos), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n DNI \t\t\t\t Nombre y Apellido \t Nota 1 \t Nota 2 \t Nota promedio \n\n");
    while(!feof(arch))
    {
        printf("\n %8d \t %30s \t %10d \t %10d \t %15.2f \n", aux.dni,aux.nombre_Apellido,aux.nota[0],aux.nota[1],aux.nota_Promedio);
        fread(&aux, sizeof(alumnos), 1, arch);
    }
    fclose(arch);
}
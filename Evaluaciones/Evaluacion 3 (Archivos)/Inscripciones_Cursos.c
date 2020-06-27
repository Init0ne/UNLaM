#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int cod;
    char descri[50];
    int cap;
    float price;
}cursos; 

typedef struct 
{
    char name[60];
    char email[50];
    int cod;
    int cant;
}solicitudes;

int contarRegistros(char[] );

int main()
{
    int opc, valido;

printf("\n \t\t\t\t --Menu principal--");
printf("\n Elija una opcion :");
printf("\n [1] - Carga de cursos");
printf("\n [2] - Carga de inscripcion");
printf("\n [3] - Listar ocupacion de cursos");
printf("\n [4] - Generar reportes");
printf("\n [5] - Salir");


    system("pause");
    return 0;
}

int contarRegistros(char name[])
{
    int cont, read;
    cursos curso;
    FILE *arch;
    arch = fopen(name,"rb");
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    cont = 0;

    while (!feof(arch))
    {
        read = fread(&curso,sizeof(cursos),1,arch);
        if(read)
        {
            cont++;
        }
    }
    return cont;
}
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

void leer_Archivo(alumnos , char []);

int main()
{
    FILE *alum, *prom, *curs, *repro;
    alumnos al;

    alum = fopen("E:\\Mathi\\UNLaM\\Elementos de Programacion\\Programas\\U10\\Ej 1\\alumnos.dat","rb");
    fread(&al,sizeof(alumnos),1,alum);
    prom = fopen("promocionados.dat","wb");
    curs = fopen("cursados.dat","wb");
    repro = fopen("reprobados.dat","wb");

    if(al.nota[0] && al.nota[1] >= 7)
    {
        fwrite(&al,sizeof(alumnos),1,prom);
    }
    else
    {
        if (al.nota[0] && al.nota[1] >= 4)
        {
            fwrite(&al,sizeof(alumnos),1,curs);
        }
        else
        {
            fwrite(&al,sizeof(alumnos),1,repro);
        }
    }
    fclose(alum);
    fclose(prom);    
    fclose(curs);    
    fclose(repro);

    leer_Archivo(al,"promocionados.dat");
    leer_Archivo(al,"cursados.dat");
    leer_Archivo(al,"reprobados.dat");

    system("pause");
    return 0;
}

void leer_Archivo(alumnos al, char n_Arch[])
{
    FILE *arch;

    arch = fopen(n_Arch,"rb");

    if(arch == NULL)
    {
        printf("Se produjo un error al intentar leer el archivo.");
        system("pause");
        exit (1);
    }

    fread(&al,sizeof(alumnos),1,arch);

    printf("\n DNI \t\t\t\t Nombre y Apellido \t Nota 1 \t Nota 2 \t Nota promedio \n\n");

    while(!feof(arch))
    {
        printf("\n %8d \t %30s \t %10d \t %10d \t %15.2f \n", al.dni,al.nombre_Apellido,al.nota[0],al.nota[1],al.nota_Promedio);
        fread(&al, sizeof(alumnos), 1, arch);
    }
    fclose(arch);
}
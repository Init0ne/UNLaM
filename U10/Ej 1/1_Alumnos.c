#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int dni;
    char nombre_Apellido[80];
    int nota1;
    int nota2;
    float nota_Promedio;
}alumnos;

void ingreso_Datos(alumnos );
void lectura_Datos(alumnos );

int main()
{
    alumnos al;

    ingreso_Datos(al);
    lectura_Datos(al);

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

void ingreso_Datos(alumnos al)
{
    FILE *alum;
    alum = fopen("alumnos.dat","ab");
    //Se corrobora que el archivo exista 
    if(alum == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    //Comienza la carga en el registro
    printf("\n Ingrese el DNI del alumno : ");
    scanf("%d", &al.dni);

    while (al.dni != 0)
    {
        printf("\n Ingrese el nombre y apellido del alumno : ");
        leer_Texto(al.nombre_Apellido,80);

        printf("\n Ingrese la nota 1 del alumno: ");
        scanf("%d", &al.nota1);
        printf("\n Ingrese la nota 2 del alumno: ");
        scanf("%d", &al.nota2);

        al.nota_Promedio = ((float)al.nota1 + (float)al.nota2) / 2;
        //Finaliza la carga 
        //-------------------------------------------------------------
        //Se copian los datos del registro en el archivo
        fwrite(&al, sizeof(alumnos), 1, alum);
        fflush(stdin);
        //-------------------------------------------------------------

        printf("\n Ingrese el DNI del alumno (o 0 para finalizar): ");
        scanf("%d", &al.dni);
    }
    fclose(alum);
}

void lectura_Datos(alumnos al)
{
    FILE *alum;
    alum = fopen("alumnos.dat","rb");
    //Se corrobora que no haya problemas
    if(alum == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&al, sizeof(alumnos), 1, alum);
    //Mientras no llegue al final del archivo lee
    printf("\n DNI \t\t\t\t Nombre y Apellido \t Nota 1 \t Nota 2 \t Nota promedio \n\n");
    while(!feof(alum))
    {
        printf("\n %8d \t %30s \t %10d \t %10d \t %15.2f \n", al.dni,al.nombre_Apellido,al.nota1,al.nota2,al.nota_Promedio);
        fread(&al, sizeof(alumnos), 1, alum);
    }
    fclose(alum);
}
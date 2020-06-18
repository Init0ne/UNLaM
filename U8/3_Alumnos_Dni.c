/*
8.3. Ingresar nombre y DNI de los alumnos de un curso. 
Como máximo el curso puede tener 50 alumnos. 
La carga finaliza con un alumno de nombre FIN. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int carga_Alumnos(char [][21], int []);
void todo_Mayusculas(char []);
void buscar_Alumnos(char [][21], int [], int );
void ordenar_Nombres(char [][21], int [], int);

int main()
{
    char nombre[50][21];
    int dni[50], cant_Alum;

    cant_Alum = carga_Alumnos(nombre,dni);

    /*
    a. Ingresar nombres de a uno en uno y buscarlos. 
    Si el nombre está en el curso mostrar su DNI y sino informar que no está. 
    Seguir ingresando nombres hasta que se ingrese un nombre igual a NOBUSCARMAS.
    */
    
    buscar_Alumnos(nombre,dni,cant_Alum);

    /*
    b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.
    */

    
    system("pause");
    return 0;
}


void leer_SinSalto(char frase[], int largo)
{
    int i = 0;

    fflush(stdin);
    fgets(frase,largo,stdin);
    
    while(frase[i] != '\0')
    {
        if(frase[i] == '\n')
        {
            frase[i] = '\0';
        }
        else
        {
            i++;
        }
    }
}

void todo_Mayusculas(char nombreaux[])
{
    int j, cant_C = 0;
    
    //Lo convierte en mayusculas
    cant_C = strlen(nombreaux);
    for(j = 0; j < cant_C; j++)
    {
        nombreaux[j] = toupper(nombreaux[j]);
    }
}

int carga_Alumnos(char nombre[][21], int dni[])
{
    int i = 0;
    char nombreaux[21];

    //Toma el nombre
    printf("\n Ingrese el nombre del alumno numero %d a continuacion : ", i+1);
    leer_SinSalto(nombreaux,21);
    //Mayusculas
    todo_Mayusculas(nombreaux);

    //Si es valido entra a tomar el DNI
    while((strcmp(nombreaux,"FIN")) != 0 && i <= 50)
    {
        strcpy(nombre[i][0], nombreaux);

        printf("\n Ingrese el DNI del alumno %s a continuacion :", nombreaux);
        scanf("%d", &dni[i]);

        i++;
        if(i <= 50)
        {
            printf("\n Ingrese el nombre del alumno numero %d a continuacion : ", i+1);
            leer_SinSalto(nombreaux,21);
            todo_Mayusculas(nombreaux);
        }
    }
}

void buscar_Alumnos(char nombre[][21], int dni[], int cant_Alum)
{
    int i;
    char nombreAux[21];

    do
    {
        printf("\n Ingrese el nombre del alumno que desea buscar : ");
        leer_SinSalto(nombreAux,21);
        todo_Mayusculas(nombreAux);

        for(i = 0; i <= cant_Alum; i++)
        {
            if((strcmp(nombreAux,nombre[i])) == 0)
            {
                printf("\n %21s %15d", nombre[i],dni[i]);
            }
            else
            {
                printf("\n El alumno ingresado no existe, intente nuevamente ! \n");
            }
            
        }
    } while ((strcmp(nombreAux,"NOBUSCARMAS")) != 0);
}

void ordenar_Nombres(char nombre[][21], int dni[], int cant_Alum)
{
    int n, i, j, auxD[15];
    char auxN[21];

    for(i = 0; i <= cant_Alum; i++)
    {
        for(j = i; j <= cant_Alum; j++)
        {
            n = 0;
            do
            {
                n++; 
            }while((strncmp(nombre[i],nombre[j+1],n) == 0));

            if((strncmp(nombre[i],nombre[j+1],n) == 1))
            {
                strcpy(auxN,nombre[j+1]);
                auxD[21]= dni[i];
                strcpy(nombre[i],nombre[j+1]);
                dni[i] = dni[j+1];
                strcpy(nombre[j+1],auxN);
                dni[i+1] = auxD[0];
            }
        }
    }
}
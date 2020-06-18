/*
8.2. 
Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona. 
Utilizando las funciones de la biblioteca string.h 
generar un tercer string formado por: NOMBRE, APELLIDO (nombre coma espacio y apellido) y mostrarlo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenar_nYa(char [], char [], char []);
void leer_SinSalto(char [], int );

int main()
{
    char nombre[21], apellido[21], nYa[41];

    printf("\n Ingrese su nombre : ");
    leer_SinSalto(nombre,21);

    printf("\n Ingrese su apellido : ");
    leer_SinSalto(apellido,21);

    concatenar_nYa(nombre,apellido,nYa);

    system("pause");
    return 0;
}

void concatenar_nYa(char nombre[], char apellido[], char nYa[])
{
    strcpy(nYa,nombre);
    strcat(nYa, ", ");
    strcat(nYa, apellido);

    puts(nYa);
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
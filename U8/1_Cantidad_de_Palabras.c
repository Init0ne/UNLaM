/*
8.1. 
Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
a. Considerar que las palabras están separadas por un único espacio. 
b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar_Espacios(char[], int);

int main()
{
    int palabras_UnEspacio, cant_c;
    char frase[501];

    //Ingresa y guarda la frase del usuario
    printf("\n Ingrese la frase deseada a continuacion (500 caracteres max.) :");
    fgets(frase,501,stdin);

    //cuenta la cantidad de caracteres ingresados
    cant_c = strlen(frase) - 1;

    palabras_UnEspacio = buscar_Espacios(frase,cant_c);

    printf("\n La frase anterior contiene %2d palabras. \n", palabras_UnEspacio);

    system("pause");
    return 0;
}

int buscar_Espacios(char frase[], int cant_c)
{
    int i, cant_Esp = 0;

    for(i = 0; i <= cant_c; i++)
    {
        if(frase[i] == ' ' && frase[i-1] != ' ')
        {
            cant_Esp ++;
        }
    }

    cant_Esp += 1;
    return cant_Esp;
}
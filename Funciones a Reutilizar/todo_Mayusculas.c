#include<stdio.h>
#include<ctype.h>

void todo_Mayusculas(char texto[])
{
    int i,largo;

    largo = strlen(texto);    
    for(i = 0; i <= largo; i++)
    {
        texto[i] = toupper(texto[i]);
    }
}
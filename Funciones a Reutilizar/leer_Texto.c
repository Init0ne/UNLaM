#include<stdio.h>

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
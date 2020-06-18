//Programa que reconoce vocales

#include<stdio.h>
#include<stdlib.h>
int main()
{
    char letra;

    //el usuario ingresa una letra
    printf("Ingrese una letra : ");
    scanf("%c", &letra);

    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
    {
        printf("\n La letra %c es una vocal y su codigo es %d \n", letra, letra);
    }
    else
    {
        printf("\n La letra %c no es una vocal . \n ", letra);
    }

    system("pause");
    return 0;
}

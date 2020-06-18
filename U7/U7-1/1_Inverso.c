//Carga , invierte y muestra vectores en funciones.

#include <stdio.h>
#include <stdlib.h>

void carga(float[]);
void inverso(float[],float[]);
void mostrar(float[]);

int main()
{
    float v1[10], v2[10];

    carga(v1);
    inverso(v1,v2);
    mostrar(v2);

    system("pause");
    return 0;
}

void carga(float v1[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("\n Ingrese un numero real :");
        scanf("%f", &v1[i]);
    }
}

void inverso(float v1[],float v2[])
{
    int j, i = 0;

    for(j = 0; j < 10; j++)
    {
        v2[9 - j]  = v1[i];
        i++;
    }
}

void mostrar(float v2[])
{
    int i;
    
    for(i = 0; i < 10; i++)
    {
        printf("\n El valor numero %d es : %.2f \n", i,v2[i]);
    }
}
//Intercala elementos de dos vectores 

#include <stdio.h>
#include <stdlib.h>

int carga(void);
void intercalar(int[],int[],int[]);

int main()
{
    int v1[5], v2[5], v3[10], h;

    v1[5] = carga();
    v2[5] = carga();
    intercalar(v1,v2,v3);

    for(h = 0; h < 10; h++)
    {
        printf("\n %d \t", v3[h]);
    }
    printf(" \n ");

    system("pause");
    return 0;
}


int carga(void)
{
    int i, v3[5];

    for(i = 0; i < 5; i++)
    {
        printf("\n Ingrese 5 numeros al vector :");
        scanf("%d", &v3[i]);
    }
    return v3[5];
}

void intercalar(int v1[], int v2[], int v3[])
{
    int i, j = 0;

    for(i = 0; i < 10; i++)
    {
        v3[j] = v1[i];
        v3[j+1] = v2[i];
        j += 2;
    }
}
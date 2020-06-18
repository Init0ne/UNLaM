//Concatenacion de vectores

#include <stdio.h>
#include <stdlib.h>

void suma_Vectores(int[],int[],int[]);

int main()
{
    int v1[5] = {1,2,3,4,5}, v2[5] = {6,7,8,9,10}, v3[10], h;

    suma_Vectores(v1,v2,v3);

    for(h = 0; h < 10; h++)
    {
        printf("\n %d \t", v3[h]);
    }
    printf(" \n ");

    system("pause");
    return 0;
}

void suma_Vectores(int v1[], int v2[], int v3[])
{
    int i, j = 0, k;

    for(i = 0; i < 5; i++)
    {
        v3[j] = v1[i];
        j++;
    }
    for(k = 0; k < 5; k++)
    {
        v3[j] = v2[k];
        j++;
    }
}
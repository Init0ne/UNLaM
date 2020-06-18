//Suma de los primeros N naturales.

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, i, fin;

    printf("\n Ingrese un numero natural :");
    scanf("%d", &num);

    fin = num - 1;

    printf("num %d",num);
    for(i = 1; i <= fin; i++)
    {
        num += i;
    }

    printf("\n La suma total es = %d \n", num);

    system("pause");
    return 0;
}

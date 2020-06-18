//Factoriales

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int fact, i, num;

    fact = 1;

    do{
        printf("\n Ingrese un numero mayor o igual a 0 ");
        scanf("%d", &num);
    }while (num < 0);

    for(i = 1; i <= num; i++)
    {
        fact *= i;
    }

    printf("\n El resultado del factorial de %d es : %d \n", num, fact);

    system("pause");
    return 0;
}

//Potencias de 2 menores a 600

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 1;

    printf("\n %d \n", n);

    while(n < 600)
    {
        n *= 2;
        if(n < 600)
        {
            printf("\n %d \n", n);
        }
    }

    system("pause");
    return 0;
}

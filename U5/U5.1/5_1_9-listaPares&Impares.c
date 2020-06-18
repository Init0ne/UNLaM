//Lista pares e impares

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int i, p;

    //Imrpime impares
    for(i = 0; i <= 30; i ++)
    {
        if(i == 0)
        {
            printf("Impares \t\t Pares \n");
        }
        else
        {
            if(i % 2 == 1)
            {
                printf("\n %d", i);
            }
            else
            {
                printf("\t\t\t %d \n", i);
            }
        }

    }
    system("pause");
    return 0;
}

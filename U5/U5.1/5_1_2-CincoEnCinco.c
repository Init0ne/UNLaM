//Sumatorio de cinco en cinco

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int i, suma = 0;

    for(i = 100; i >= 50; i -=5)
    {
        suma += i;
    }

    printf("\n La suma total es %d \n", suma);

    system("pause");
    return 0;
}

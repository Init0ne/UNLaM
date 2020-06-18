#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1, n2, Centena, Decena, Unidad;

    printf("\nIngrese un numero de 3 cifras : ");
    scanf("%d", &n1);

    Centena = n1 / 100;
    n2 = n1 % 100;
    Decena = n2 / 10;
    Unidad = n2 % 10;

    printf("\nLa centena es %d, la decena es %d y la unidad es %d \n", Centena, Decena, Unidad);

    getch();
    system("pause");
    return 0;
}

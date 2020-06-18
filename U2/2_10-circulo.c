#include<stdio.h>
#include<stdlib.h>

int main()
{
    const float Pi = 3.14;
    float radio, sup, perim, vol;

    printf("\nIngrese el radio de su circulo : ");
    scanf("%f", &radio);

    sup = Pi * radio * radio;
    perim = 2 * Pi * radio;
    vol = (4/3) * Pi * radio * radio * radio;

    printf("\n La superficie del circulo es = %f, el perimetro es = %f, y su volumen es = %f \n", sup, perim, vol);

    getch();
    system("pause");
    return 0;
}

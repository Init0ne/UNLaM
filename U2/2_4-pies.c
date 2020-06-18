#include<stdio.h>
#include<stdlib.h>
int main()
{
    float Pies, Yardas, Pulgadas, Cms, Metros;

    //El usuario ingresa la medida en pies.
    printf("\nIngrese la medida en pies : ");
    scanf("%f", &Pies);

    //Declara operaciones
    Yardas = Pies * 3;
    Pulgadas = Pies * 12;
    Cms = Pulgadas * 2.54;
    Metros = Cms / 100;

    //Imprime medidas
    printf("\nLa medida en yardas es : %.2f \n", Yardas);
    printf("\nLa medida en pulgadas es : %.2f \n", Pulgadas);
    printf("\nLa medida en centimetros es : %.2f \n", Cms);
    printf("\nLa medida en metros es : %.2f \n", Metros);

    getch();
    system("pause");
    return 0;
}

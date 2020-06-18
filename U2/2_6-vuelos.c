#include<stdio.h>
#include<stdlib.h>
int main()
{
    int Turista, Primera, TuristaTotal, PrimeraTotal, Recaudacion;

    printf("\nIngrese la cantidad de vuelos en clase turista : ");
    scanf("%d", &Turista);

    printf("\nIngrese la cantidad de vuelos en primera clase : ");
    scanf("%d", &Primera);

    TuristaTotal = Turista * 8800;
    PrimeraTotal = Primera * ( Turista + ((Turista * 30) / 100));
    Recaudacion = PrimeraTotal + TuristaTotal;

    printf("\nLa recaudacion total es de : %d \n", Recaudacion);

    getch();
    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
    float Cant_Horas, Precio_Horas, Sueldo_Final;

    // El usuario introduce la cant. de horas trabajadas por el empleado.
    printf("Cantidad de horas trabajadas : ");
    scanf("%f",&Cant_Horas);

    // El usuario introduce el precio de las horas de ese empleado.
    printf("\nPrecio por hora : ");
    scanf("%f",&Precio_Horas);

    Sueldo_Final = Cant_Horas * Precio_Horas;

    // El usuario recibe el total a pagar al empleado.
    printf("\nEl sueldo total del empleado es : %f \n", Sueldo_Final);
    getch();
    system("pause");
    return 0;
}

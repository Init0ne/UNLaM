//Promedio de edades

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int suma, edad, cont;
    float prom;

    suma = 0;
    cont = 0;

   printf("Ingrese las edades (0 para finalizar )");
   scanf("%d", &edad);

   while(edad > 0)
   {
       suma += edad;
       cont ++;
       printf("Ingrese las edades (0 para finalizar )");
       scanf("%d", &edad);
   }
   if(cont > 0)
   {
       prom = suma / cont;
       printf("\n El promedio de edades es %.2f \n", prom);
   }
   else
   {
       printf("\n No se ingreso ningun dato. \n");
   }

    system("pause");
    return 0;
}

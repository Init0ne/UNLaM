//Descuentos en tienda

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int cont = 0;
    float prom, ventas = 0, desc, impor, total;

    while(impor > 0)
          {
              printf("\n Ingrese el importe del producto : ");
              scanf("%f", &impor);

              if(impor < 50)
              {
                  desc = impor * 3.5 / 100;
              }
              else
              {
                  if(impor < 150)
                  {
                      desc = impor * 10 /100;
                  }
                  else
                  {
                      if(impor < 300)
                      {
                          desc = impor * 20 / 100;
                      }
                      else
                      {
                          desc = impor * 25 / 100;
                      }
                  }
              }
              total = impor - desc;
              cont ++;
              ventas += total;

              printf("\n El importe total a pagar es de $ %.2f \n", total);
              printf("\n Descuento realizado de $ %.2f \n", desc);
          }

          if(cont != 0)
          {
              prom = ventas / cont;
              printf("\n El promedio de ventas es de $ %.2f \n", prom);
          }

    system("pause");
    return 0;
}

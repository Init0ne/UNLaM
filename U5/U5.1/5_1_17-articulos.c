//Articulos

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, cod, cod_Max;
    float price, price_Max = 0, price_Min = 0;

    printf("\n Cuantos codigos va a ingresar? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\n Ingrese el codigo del producto seguido de su valor :");
        scanf("%d%f", &cod, &price);

        if(price_Min == 0)
        {
            price_Min = price;
        }
        if(price > price_Max)
        {
            price_Max = price;
            cod_Max = cod;
        }
        else
        {
            if(price < price_Min)
            {
                price_Min = price;
            }
        }
    }

    printf("\n El codigo del articulo mas caro es %d y el precio del articulo mas barato es %.2f \n", cod_Max, price_Min);

    system("pause");
    return 0;
}

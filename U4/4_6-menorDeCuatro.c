//Menor de 4 enteros y su posicion

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1, n2, n3, n4 ,Menor, Posicion;

    //Ingresa numeros.
    printf("Ingrese el primer numero : ");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero : ");
    scanf("%d", &n2);
    printf("Ingrese el tercer numero : ");
    scanf("%d", &n3);
    printf("Ingrese el cuarto numero : ");
    scanf("%d", &n4);

    //Condicionales menor .
    if(n1 < n2 && n1 < n3 &&  n1 < n4)
    {
        Menor = n1;
        Posicion = 1;
    }
        if(n2 < n1 && n2 < n3 && n2 < n4)
    {
        Menor = n2;
        Posicion = 2;
    }
        if(n3 < n2 && n3 < n1 && n3 < n4)
    {
        Menor = n3;
        Posicion = 3;
    }
        if(n4 < n2 && n4 < n3 && n4 < n1)
    {
        Menor = n4;
        Posicion = 4;
    }

    //Respuesta al usario.
    printf("\n Los numeros ingresados fueron : %d %d %d %d \n", n1, n2, n3, n4);
    printf("\n El numero menor es : %d , ingresado en la posicion numero : %d \n", Menor, Posicion);

    system("pause");
    return 0;
}

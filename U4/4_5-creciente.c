//Ordena 3 enteros de > a <

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1, n2, n3, Mayor, Medio, Menor;

    printf("Ingrese el primer numero : ");
    scanf("%d", &n1);
    printf("Ingrese el segundo numero : ");
    scanf("%d", &n2);
    printf("Ingrese el tercer numero : ");
    scanf("%d", &n3);

    if (n1 > n2 )
    {
        if (n1 > n3)
        {
            if (n2 > n3)
            {
                Mayor = n1;
                Medio = n2;
                Menor = n3;
            }
            else{
                Mayor = n1;
                Medio = n3;
                Menor = n2;
            }
        }
        else{
            Mayor = n3;
            Medio = n1;
            Menor = n2;
        }
    }
    else{
        if(n2 > n3)
        {
            if(n1 > n3)
            {
                Mayor = n2;
                Medio = n1;
                Menor = n3;
            }
            else{
                Mayor = n2;
                Medio = n3;
                Menor = n1;
            }
        }
        else{
            Mayor = n3;
            Medio = n2;
            Menor = n1;
        }
    }

    printf("\n El orden de los numeros de menor a mayor es : %d %d %d \n", Menor, Medio, Mayor);

    system("pause");
    return 0;
}

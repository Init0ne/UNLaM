#include <stdio.h>
#include <stdlib.h>

int IngresoEntero();
int MostrarMenu(int, int);
void Operaciones(int, int, int);

int main()
{
    int n1, n2, opc;
    float resultado;
    
    opc = 1;

    while(opc != 6)
    {
        n1 = IngresoEntero();
        n2 = IngresoEntero();

        //Llamada funcion MostrarMenu
        opc = MostrarMenu(n1,n2);

        //Realiza operaciones si se eligio una opcion correspondiente
        if(opc < 5)
        {
            do{
                Operaciones(n1,n2,opc);
                opc = MostrarMenu(n1,n2);
            }while(opc < 5);
        }
        else{
            system("cls");
        }
    }

    return 0;
}

int IngresoEntero()
{
    int n;
    printf("\n Ingrese un numero entero : ");
    scanf("%d", &n);
    return n;
}

int MostrarMenu(int n1, int n2)
{
    int opc;

    system("cls");
    printf("\n Menu de opciones");
    printf("\n ---- -- --------");
    printf("\n Numero 1 : %d  Numero 2 : %d", n1, n2);
    printf("\n 1) Sumar \n 2) Restar \n 3) Multiplicar \n 4) Dividir \n 5) Ingresar Nuevos Numeros \n 6) Salir");
    do{
        printf("\n Ingrese su opcion : ");
        scanf("%d", &opc);
    }while(opc < 1 || opc > 6);
    return opc;
    
}

void Operaciones(int n1, int n2, int opc)
{   
    int result_Int;
    float resultado;

    switch(opc)
    {
        case 1 : result_Int = n1 + n2;
                printf("\n El resultado de la suma es : %d \n", result_Int);
                system("pause");
        break;
        case 2 : result_Int = n1 - n2;
                printf("\n El resultado de la resta es : %d \n", result_Int);
                system("pause");
        break;
        case 3 : result_Int = n1 * n2;
                printf("\n El resultado de la multiplicacion es : %d \n", result_Int);
                system("pause");
        break;
        case 4 : if(n1 != 0 && n2 != 0)
        {
            resultado = (float)n1 / n2;
            printf("\n El resultado de la division es : %.4f \n", resultado);
            system("pause");
        } 
        else
        {
            printf("\n Es imposible divir por 0 ! \n");
            system("pause");
        }
        break;
        default : break;
    }
}
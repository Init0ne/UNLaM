//Programa de pruebas

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int sumar (int, int);
int restar (int, int);
float multiplicar (int, int);
float dividir (int, int);
int ingreso ();

int main()
{   
    int num1, num2, opcion, s, r, i, n1, n2;
    float m, d;
    printf("INGRESAR DOS NUMEROS:");
    scanf("%d", &num1); scanf("%d", &num2);
    printf("MENU DE OPCIONES\n ---- -- --------\n Numero 1: %d  Numero 2: %d\n", num1, num2);
    printf("1) Sumar\n 2) Restar\n 3) Multiplicar\n 4) Dividir\n 5) Ingresar dos valores nuevos\n 6) Salir\n");
    printf ("Ingrese su opcion:"); scanf("%d",&opcion);
    
    while(opcion!=6)
    {
        switch (opcion)
        {
            case 1: s= sumar (num1, num2); 
                        printf("El resultado de la suma es: %d\n", s); 
                        break;
            case 2: r= restar (num1,  num2); printf("El resultado de la resta es: %d\n", r); break;
            case 3: m= multiplicar (num1, num2); printf("El resultado de la multiplicacion es: %f\n", m);break;
            case 4: d= dividir(num1, num2); printf("El resultado de la division es: %f\n", d); break;
            case 5: i= ingreso (); printf("Ingresar segundo valor: "); scanf("%d", &n2); break;
            default: break;
        }
    }
    
    return 0; 
}

int sumar (int num1, int num2){
    int suma;
    suma=num1+num2;
    return suma;
}
int restar (int num1, int num2){
    int resta;
    resta=num1-num2;
    return resta;
}
float multiplicar (int num1, int num2){
    float multiplica;
    multiplica=num1*num2;
    return multiplica;
}
float dividir (int num1, int num2){
    float divide;
    divide=(float)num1/(float)num2;
    return divide;
}
int ingreso (){
    int n1;
    printf("Ingrese un nuevo valor: ");
    scanf("%d", &n1);
    return n1;
}
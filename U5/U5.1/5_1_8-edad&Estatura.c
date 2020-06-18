//Edad y estatura de alumnos

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int edad, i, cont = 0, sumaEdad = 0, sumaEstat = 0, contEdad = 0, contEstat = 0;
    float estat, estatProm, edadProm ;

    for(i = 0; i < 2; i++)
    {
        //El usuario ingresa los datos.
        printf("\n Ingrese la edad del alumno : ");
        scanf("%d", &edad);
        printf("\n Ingrese la estatura del alumno : ");
        scanf("%f", &estat);

        //Cuenta los menores de 10
        if(edad > 10)
        {
            contEdad ++;
        }
        //Cuenta los de estatura menor a 1.4
        if(estat < 1.40)
        {
            contEstat ++;
        }

        //Realiza sumas para el promedio
        sumaEdad += edad;
        sumaEstat += estat;
        cont ++;

    }

    //Promedios
    edadProm = sumaEdad / cont;
    estatProm = sumaEstat / cont;

    //Respuesta al usuario
    printf("\n La edad promedio es de %.2f \n", edadProm);
    printf("\n La estatura promedio es de %.2f \n", estatProm);
    printf("\n La cantidad de alumnos mayores a 10 anos es de %d \n", contEdad);
    printf("\n La cantidad de alumnos con una alatura menor a 1.40 m es de %d \n", contEstat);

    system("pause");
    return 0;
}

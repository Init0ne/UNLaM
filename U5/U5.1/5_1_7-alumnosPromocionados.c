//Alumnos Promocionados

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nota, leg, cont, i;

    for(i = 0; i < 20; i++)
    {
        printf("\n Ingrese el numero de legajo :");
        scanf("%d", &leg);
        printf("\n Ingrese la nota del alumno : ");
        scanf("%d", &nota);

        if(nota >= 7)
        {
            printf("\n El alumno con legajo numero %d, ha promocionado! \n", leg);
        }
        else
        {
            cont++;
        }
    }

    printf("\n La cantidad de alumnos aplazados es de : %d \n", cont);


    system("pause");
    return 0;
}

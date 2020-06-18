//Dni

#include<stdlib.h>
#include <stdio.h>

int main()
{
    int nota, dni, notaMax = 0, dniMax = 0, i;

    for(i = 0; i < 10; i++)
    {
        printf("\n Ingrese la nota del alumno : ");
        scanf("%d", &nota);
        printf("\n Ingrese el DNI del alumno : ");
        scanf("%d", &dni);

        if(nota > notaMax)
        {
            notaMax = nota;
            dniMax = dni;
        }
    }

    printf("\n La nota max es de %d del alumno con dni numero %d \n", notaMax, dniMax);

    system("pause");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct
{
    int cod;
    float precio;
    int stock;
}medicamentos;

int ingreso(medicamentos []);
void busqueda_Meds(medicamentos [], int );
void informe(medicamentos [], int );

int main()
{
int cant_Meds;
medicamentos meds[50];

printf("\n A continuacion ingrese la informacion correspondiente a cada articulo.\n");
cant_Meds = ingreso(meds);

system("cls");

printf("\n Consulte el valor de su medicamento.\n");
busqueda_Meds(meds,cant_Meds);

system("cls");

printf("\n A continuacion se muestran los articulos con un stock menor a 10 unidades.\n");
informe(meds,cant_Meds);

    system("pause");
    return 0 ;
}

int ingreso(medicamentos meds[])
{
    int i = 0;

    printf("\n Ingrese el codigo del medicamento : ");
    scanf("%d", &meds[i].cod);

    while(meds[i].cod != -1)
    {
        printf("\n Ingrese el valor del medicamento :");
        scanf("%f", &meds[i].precio);

        printf("\n Ingrese la cantidad de medicamentos en stock :");
        scanf("%d", &meds[i].stock);

        i++;

        system("cls");

        printf("\n Ingrese el codigo del medicamento : ");
        scanf("%d", &meds[i].cod);
    }
    return i;
}

void busqueda_Meds(medicamentos meds[], int cant_Meds)
{
    int i, codAux, indice;
    char continuar;

    do
    {
        printf("\n Ingrese el codigo del medicamento a consultar :");
        scanf("%d", &codAux);

        indice = -1;

        for(i = 0; i < cant_Meds; i++)
        {
            if(codAux == meds[i].cod)
            {
                indice = i;
            }
        }
        if(indice != -1)
        {
            printf("\n El precio del medicamento consultado es $%4.2f.\n", meds[indice].precio);
            printf("\n Desea consultar otro medicamento? (S/N)");
            fflush(stdin);
            scanf("%c",&continuar);
            continuar = toupper(continuar);
        }
        else
        {
            printf("\n Lo sentimos, el codigo ingresado no corresponde a ningun medicamento, intentelo nuevamente.\n");
            printf("\n Desea consultar otro medicamento? (S/N)");
            fflush(stdin);
            scanf("%c",&continuar);
            continuar = toupper(continuar);
        }
        
    } while (continuar == 'S');
}

void informe(medicamentos meds[], int cant_Meds)
{
    int i;

    for(i = 0; i < cant_Meds; i++)
    {
        if(meds[i].stock < 10)
        {
            printf("\n El articulo %3d posee menos de 10 unidades en stock.\n", meds[i].cod);
        }
    }
    printf("\n\n");
}


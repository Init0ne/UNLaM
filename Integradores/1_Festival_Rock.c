#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void cargar_MatrizCapacidad(int [][5]);
void leer_Texto(char [], int );
int indice_Sector(char [], char [][11]);
void solicitud_Entradas(char [][11], int [], int [][5], float [][4]);
void informe_Recaudacion(float [][4], char [][11]);
void full_Agotado(int [][5], char [][11]);
void recaudacion_diaCuatro(float [][4], char [][11]);
void recaudacion_Total(float  [][4]);

int main()
{
    char sector[5][11] = {"BANDEJA",
                            "RAMPA",
                            "PALCOS",
                            "CABECERA",
                            "CAMPO"};
    int costo_xSector[5] = {1000,800,2500,1400,3000}, capacidad_xSector[4][5] = {5000,5000,900,1200,10000};
    float total[3][4] = {{0}};

    //Inicializa la cantidad de localidades por sector y dia
    cargar_MatrizCapacidad(capacidad_xSector);
    //Inicia el sistema de carga
    printf("\n Bienvenidos al sistema de solicitud de entradas !");
    solicitud_Entradas(sector,costo_xSector,capacidad_xSector,total);   
    //Informe recaudacion
    printf("\n Informe de recaudacion diario. \n");
    informe_Recaudacion(total,sector);
    //Informe sectores y dias agotados
    full_Agotado(capacidad_xSector,sector);
    //Vendieron menos de 1.500.000 el dia 4
    recaudacion_diaCuatro(total,sector);
    //Recaudacion total
    recaudacion_Total(total);
    
    system("pause");
    return 0;
}

void cargar_MatrizCapacidad(int capacidad_xSector[][5])
{
    int i,j;
    
    for(i = 1; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            capacidad_xSector[i][j] = capacidad_xSector[0][j];
        }
    }
}

void leer_Texto(char texto[], int largo)
{   
    int i = 0;

    fflush(stdin);
    fgets(texto,largo,stdin);

    while(texto[i] != '\0')
    {
        if(texto[i] == '\n')
        {
            texto[i] = '\0';
        }
        else
        {
            i++;
        }
    }
}

int indice_Sector(char sectorAux[], char sector[][11])
{
    int i = 0, indice = -1;

    while(indice < 0 && i < 5)
    {
        if(strcmpi(sectorAux,sector[i])== 0)
        {
            indice = i;
        }
        else
        {
            i++;
        }
    }
    return indice;
}

void solicitud_Entradas(char sector[][11], int costo_xSector[], int capacidad_xSector[][5], float total[][4])
{
    int indice_Sec, cant_Entradas, dia,i;
    char sectorAux[11], compra;
    float total_Venta, descuento;

    while((strcmpi(sectorAux,"FIN")) != 0)
    {
        //Ingresa el dia y se valida
        do
        {
            printf("\n Ingrese el dia :");
            fflush(stdin);
            scanf("%d", &dia);
        }while(dia < 1 || dia > 4);
        dia = dia - 1;
        
        //Ingresa el nombre del sector y recupera el indice en la matriz
        printf("\n Ingrese el sector :");
        leer_Texto(sectorAux,11);
        indice_Sec = indice_Sector(sectorAux,sector);

        //si sigue la carga
        if((strcmpi(sectorAux,"FIN")) != 0)
        {
            //Si hay lugares en el sector seleccionado
            if(capacidad_xSector[dia][indice_Sec] > 0)
            {
                do
                {
                    printf("\n Ingrese la cantidad de localidades deseadas :");
                    scanf("%d", &cant_Entradas);
                } while (cant_Entradas < 0);
                //Comprobar que no se exceda la capacidad
                if(capacidad_xSector[dia][indice_Sec] - cant_Entradas >= 0)
                {
                    //Comprobar si se aplica el descuento
                    if(cant_Entradas > 10)
                    {
                        if(dia == 3 || dia == 4)
                        {
                            descuento = ((float)cant_Entradas * (float)costo_xSector[indice_Sec]) * 10 / 100;
                            total_Venta = ((float)cant_Entradas * (float)costo_xSector[indice_Sec]) - descuento;
                            printf("\n El total de su compra es de %.2f", total_Venta);
                        }
                        else
                        {
                            total_Venta = (float)cant_Entradas * (float)costo_xSector[indice_Sec];
                            printf("\n El total de su compra es de %.2f", total_Venta);
                        }
                    }
                    else
                    {
                        total_Venta = (float)cant_Entradas * (float)costo_xSector[indice_Sec];
                        printf("\n El total de su compra es de %.2f", total_Venta);
                    }
                }
                else
                {
                    printf("\n Lo sentimos , la cantidad de localidades restantes en el sector es de %d !",capacidad_xSector[dia][indice_Sec]);
                }
            }
            else
            {
                printf("\n Disculpe, las entradas en el sector seleccionado ya han sido agotadas, intente con otro!");
            }
            if((strcmpi(sectorAux,"FIN")) != 0)
            {
                //Confirmacion de la compra
                printf("\n Desea realizar la compra ? (S/N)");
                fflush(stdin);
                scanf("%c",&compra);
                compra = toupper(compra);
                //Si la compra se realiza con exito
                if(compra == 'S')
                {
                    capacidad_xSector[dia][indice_Sec] -= cant_Entradas;
                    total[dia][indice_Sec] += total_Venta;
                    printf("\n Su compra ha sido procesada con exito !");
                }
                else
                {
                    printf("\n Lo sentimos, intentelo nuevamente!");
                }
            }
        }
    }
}

void informe_Recaudacion(float total[][4], char sector[][11])
{
    int i,j;
    char informe[5][10] ={
        "SECTOR",
        "Dia 1",
        "Dia 2",
        "Dia 3",
        "Dia 4"
    };

    printf("\n");
    for(i = 0; i < 5; i++)
    {
        printf(" %15s ", informe[i]);
    }
    printf("\n");
    for(i = 0; i < 5; i++)
    {
        printf("\n%15s", sector[i]);
        for(j = 0; j < 4; j++)
        {
            printf("%15.2f",total[j][i]);
        }
    }
    printf("\n");
}

void full_Agotado(int capacidad_xSector[][5], char sector[][11])
{
    int i,j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(capacidad_xSector[i][j] == 0)
            {
                printf("\n Sector %s agotado dia %d", sector[j],i+1);
            }
        }
    }
    printf("\n");
}

void recaudacion_diaCuatro(float total[][4], char sector[][11])
{
    int i;

    printf("\n El/Los sectores que vendieron menos de $1,500,000 el dia 4 fueron : ");
    for(i = 0; i < 5; i++)
    {
        if(total[3][i] < 1500000)
        printf("\n %s",sector[i]);
    }
    printf("\n");
}

void recaudacion_Total(float total [][4])
{
    int i, j;
    float sec_total[4] = {0}, rec_total = 0;

    //Suma todos los dias del sector
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 5; j++)
        {
            sec_total[i] += total[j][i];
        }
    }
    //Suma todos los sectores
    for(i = 0; i < 5; i++)
    {
        rec_total += sec_total[i];
    }

    printf("\n El total recaudado en el festival fue de $%.2f \n", rec_total);
}
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int dni, cant_Pasajeros, cant_Dias, cat,  categoria, tot_Importe, menor_MontoDNI;
    char ya_Alojado;
    float descuento_S, bono_Adicional, tot_aPagar;

    int cat1 = 0, cat2 = 0, cat3 = 0, cat4 = 0, s = 0;
    float descuento_S_Total = 0, total_Cat1 = 0, total_Cat2 = 0, total_Cat3 = 0, total_Cat4 = 0, menor_Monto = 9999999;

    printf("\n \t\t\t\tBienvenidos al hotel -Corona del Rey!- \n\n");
    
    //Ingresa el primer DNI
    printf("\n Ingrese el DNI del cliente (o -1 para finalizar la carga) : ");
    scanf("%d", &dni);

    //Ingresa a la carga de datos de clientes
    while(dni != -1)
    {
        //Ingresa cantidad de pasajeros y los valida
        do
        {
            printf("\n Ingrese la cantidad de pasajeros (1-8) : ");
            scanf("%d", &cant_Pasajeros);
        } while (cant_Pasajeros < 1 || cant_Pasajeros > 8);
         //--------------------------------------------------------------------------
        
        //Ingresa cantidad de dias y lo valida
        do
        {
            printf("\n Ingrese la cantidad de dias a hospedarse (7-21) : ");
            scanf("%d", &cant_Dias);
        } while (cant_Dias < 7 || cant_Dias > 21);
         //--------------------------------------------------------------------------

        //Consulta si el cliente ya se alojo en el hotel y lo valida
        do
        {
            printf("\n El cliente ya ha sido alojado en el hotel anteriormente? (S/N) : ");
            fflush(stdin);
            scanf("%c", &ya_Alojado);
            ya_Alojado = toupper(ya_Alojado);
        } while (ya_Alojado != 'S' && ya_Alojado != 'N');
         //--------------------------------------------------------------------------
        
        //Muestra categorias del hotel 
        printf("\n A continuacion se muestran las categorias de alojamiento. \n");
        printf("\n Categoria 1 = Precio x dia de estadia $1000 x pasajero \n");
        printf("\n Categoria 2 = Precio x dia de estadia $1500 x pasajero \n");
        printf("\n Categoria 3 = Precio x dia de estadia $1700 x pasajero \n");
        printf("\n Categoria 4 = Precio x dia de estadia $2000 x pasajero \n");
         //--------------------------------------------------------------------------
        //Seleccion y validacion de categoria
        do
        {
            printf("\n Por favor, seleccione la categoria deseada : ");
            scanf("%d", &cat);
        } while (cat < 1 || cat > 4);

        switch (cat)
        {
            case 1:
                cat1 ++;
                categoria = 1000;
                break;

            case 2:
                cat2 ++;
                categoria = 1500;
                break;

            case 3:
                cat3 ++;
                categoria = 1700;
                break;

            case 4:
                cat4 ++;
                categoria = 2000;
                break;
        
            default:
                break;
        }
         //--------------------------------------------------------------------------

        //Total de estadia
        tot_Importe = (cant_Pasajeros * categoria) * cant_Dias;
         //--------------------------------------------------------------------------

        //Descuentos seteados en 0
        descuento_S = 0;
        bono_Adicional = 0;
         //--------------------------------------------------------------------------
        
        //Corrobora si ya fue alojado con anterioridad y calcula el descuento
        if(ya_Alojado == 'S')
        {
            descuento_S = (float)tot_Importe * 10 / 100;
            descuento_S_Total += descuento_S;
            s++;
        }
         //--------------------------------------------------------------------------

        //Corrobora el bono adicional en base a los dias de alojamiento
        if(cant_Dias > 14)
        {
            bono_Adicional = (float)tot_Importe * 10 / 100;
        }
        else
        {
            if(cant_Dias > 7)
            {
                bono_Adicional = (float)tot_Importe * 5 / 100;
            }
        }
         //--------------------------------------------------------------------------
        
        //Calcula el total a pagar aplicando descuentos
        tot_aPagar = (float)tot_Importe - descuento_S - bono_Adicional;
         //--------------------------------------------------------------------------

        //Muestra en pantalla la informacion respectiva al cliente
        printf("\n El importe total de la estadia es de $%d .", tot_Importe);
        printf("\n La cantidad de dias de alojamiento ingreados es de %d .", cant_Dias);
        printf("\n La categoria selecciona fue la numero %d .", cat);
        printf("\n El importe total a pagar es de $%.2f .", tot_aPagar);
         //--------------------------------------------------------------------------

        //Suma el total a la categoria elegida para el resumen final
        switch (cat)
        {
            case 1:
                total_Cat1 += tot_aPagar;
                break;

            case 2:
                total_Cat2 += tot_aPagar;
                break;

            case 3:
                total_Cat3 += tot_aPagar;
                break;

            case 4:
                total_Cat4 += tot_aPagar;
                break;
        
            default:
                break;
        }
         //--------------------------------------------------------------------------

        //Guarda el cliente con el monto de estadia mas bajo
        if(tot_Importe < menor_Monto)
        {
            menor_Monto = tot_Importe;
            menor_MontoDNI = dni;
        }
         //--------------------------------------------------------------------------

        //Ingresa el DNI para continuar el ciclo
        printf("\n\n Ingrese el DNI del cliente (o -1 para finalizar la carga) : ");
        scanf("%d", &dni);
        //--------------------------------------------------------------------------
    }

    printf("\n La carga a finalizado con exito! \n");
    system("pause");
    system("cls");

    //Cantidad y monto por categoria
    printf("\n A continuacion se muestra un resumen de los pedidos de reserva y el monto total por categorias. \n\n");
    printf("\n Categoria \t\t Reservas \t\t    Monto \n\n");
    printf("\n Cat 1     \t\t %8d \t\t $%8.2f \n", cat1, total_Cat1);
    printf("\n Cat 2     \t\t %8d \t\t $%8.2f \n", cat2, total_Cat2);
    printf("\n Cat 3     \t\t %8d \t\t $%8.2f \n", cat3, total_Cat3);
    printf("\n Cat 4     \t\t %8d \t\t $%8.2f \n", cat4, total_Cat4);
    system("pause");
    system("cls");
    //--------------------------------------------------------------------------

    //Estadia de menor monto y DNI del cliente
    printf("\n A continuacion se muestra el DNI del cliente con la estadia de menor valor y el monto. \n\n");
    printf("\n El DNI del cliente es %d, y el monto es de $%.2f \n", menor_MontoDNI,menor_Monto);
    system("pause");
    system("cls");
    //--------------------------------------------------------------------------

    //Cantidad de clientes que ya habian sido alojados en el hotel y descuento total realizado
    printf("\n A continuacion se muestra un resumen con informacion sobre los clientes que ya se habian alojado en el hotel. \n\n");
    printf("\n Clientes \t\t Descuento total realizado \n");
    printf("\n %8d \t\t %15.2f", s,descuento_S_Total);
    printf("\n");
    //--------------------------------------------------------------------------

    system("pause");
    return 0;
}
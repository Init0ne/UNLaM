#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cargar_Codigos(char [][7]);
void cargar_Precios(float []);
void ingreso_Mercaderia(char [][7],int []);
void valor_Stock(char [][7], int [], float [], float[]);
void mostrar_Cant_Articulos(char [][7], int []);
void mas_1Millon(char [][7], float []);
void menos_100Unidades(char [][7], int []);
void mayor_Cantidad(char [][7], int []);
void sin_Stock(char [][7], int []);

int main()
{
    float precio_xUnidad[100], total_xArticulo[100] = {0};
    char cod[100][7];
    int cant_xProducto[100] = {0};

    //Se cargan los codigos y precios
    cargar_Codigos(cod);
    cargar_Precios(precio_xUnidad);

    //Ingresa la mercaderia y se valida
    ingreso_Mercaderia(cod,cant_xProducto);
    system("pause");
    system("cls");

    //A- total stock $
    valor_Stock(cod,cant_xProducto,precio_xUnidad,total_xArticulo);
    system("pause");
    system("cls");
    //Muestra la cantidad por articulos
    mostrar_Cant_Articulos(cod,cant_xProducto);
    system("pause");
    system("cls");

    //B- Mostrar codigo de articulos que superen el $1.000.000
    mas_1Millon(cod,total_xArticulo);
    system("pause");
    system("cls");

    //C-Muestra los articulos con menos de 100 unidades
    menos_100Unidades(cod,cant_xProducto);
    system("pause");
    system("cls");

    //D-Articulos con mayor cantidad de unidades
    mayor_Cantidad(cod,cant_xProducto);
    system("pause");
    system("cls");

    //E-Informar articulos sin stock
    sin_Stock(cod,cant_xProducto);
    system("pause");
    system("cls");

    system("pause");
    return 0;
}

void cargar_Codigos(char cod[][7])
{
    int i, j, num_Num, num_Letra;
    char art_Aux[7], num[4] = {"000"};

    for(i = 0; i < 10; i++)
    {
        //Codigo Ascii letra A incrementando
        num_Letra = 65;

        num_Letra += i;
        char letra[3] = {num_Letra};
        for(j = 0; j < 10; j++)
        {   
            //Codigo Ascii numero 0 incrementando
            num_Num = 48;
            strcpy(art_Aux,letra);
            strcat(art_Aux,"_");
            num_Num += j;
            char num_Final[2] = {num_Num};
            strcat(art_Aux,num);
            strcat(art_Aux,num_Final);
            strcpy(cod[(i*10)+j],art_Aux);
        }
    }

}

void cargar_Precios(float precio_xUnidad[])
{
    int i;
    float precio = 10.5;

    for(i = 0; i < 100; i++)
    {
        precio_xUnidad[i] = precio * 1.05 * (i+1);
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

int verificar_Codigo(char cod_Aux[], char cod[][7])
{
    int i = 0, indice = -1;

    while(indice < 0 && i < 100)
    {
        if(strcmpi(cod_Aux,cod[i])== 0)
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

void ingreso_Mercaderia(char cod[][7],int cant_xProducto[])
{
    int n_Pedido, cant, indice;
    char cod_Aux[7];

    do
    {
        printf("\n Ingrese el numero de pedido:");
        scanf("%d", &n_Pedido);
    } while (n_Pedido < 0);

    while(n_Pedido != 0)
    {
        printf("\n Ingrese el codigo del articulo :");
        leer_Texto(cod_Aux,7);
        //Verifica si el codigo existe y recupera su indice
        indice = verificar_Codigo(cod_Aux,cod);
        //Si el codigo existe
        if(indice >=0)
        {
            do
            {
                printf("\n Ingrese la cantidad de unidades compradas :");
                scanf("%d", &cant);
            }while(cant < 0);
            cant_xProducto[indice] += cant;
        }
        do
        {
            printf("\n Ingrese el numero de pedido:");
            scanf("%d", &n_Pedido);
        } while (n_Pedido < 0);
    }    
}

void valor_Stock(char cod[][7], int cant_xProducto[], float precio_xUnidad[], float total_xArticulo[])
{
    int i;
    float total = 0;

    //Calcula y muestra el valor total del stock
    for(i = 0; i < 100; i++)
    {
        total_xArticulo[i] = (float)cant_xProducto[i] * precio_xUnidad[i];
        total += total_xArticulo[i];
    }
    printf("\n El total valorizado del stock es : $%.2f \n",total);
}

void mostrar_Cant_Articulos(char cod[][7], int cant_xProducto[])
{
    int i;

    //Muestra cantidad de unidades por articulo
    printf("\n Articulo \t\t Cantidad \n");
    for(i = 0; i < 100 ; i++)
    {
        printf("\n %10s \t\t %10d", cod[i], cant_xProducto[i]);
    }
    printf("\n");
}

void mas_1Millon(char cod[][7], float total_xArticulo[])
{
    int i;

    for(i = 0; i < 100; i++)
    {
        if(total_xArticulo[i] > 1000000)
        {
            printf("\n La valoracion total del articulo %7s, supera la suma de $1.000.000. \n",cod[i]);
        }
    }
}

void menos_100Unidades(char cod[][7], int cant_xProducto[])
{
    int i;

    for(i = 0; i < 100; i++)
    {
        if(cant_xProducto[i] < 100)
        {
            printf("\n El articulo %7s posee menos de 100 unidades.", cod[i]);
        }
    }
    printf("\n");
}

void mayor_Cantidad(char cod[][7], int cant_xProducto[])
{
    int i, mayor;

    mayor = 0;
    //Detecta mayor
    for(i = 0; i < 100; i++)
    {
        if(cant_xProducto[i] > mayor)
        {
            mayor = cant_xProducto[i];
        }
    }  
    //Detecta iguales al mayor
    for(i = 0; i < 100; i++)
    {
        if(cant_xProducto[i] == mayor)
        {
            printf("\n El articulo %7s posee la mayor cantidad de unidades (%d). \n",cod[i],cant_xProducto[i]);
        }
    }
}

void sin_Stock(char cod[][7], int cant_xProducto[])
{
    int i;

    for(i = 0; i < 100; i++)
    {
        if(cant_xProducto[i] == 0)
        {
            printf("\n El articulo %7s no posee stock.\n", cod[i]);
        }
    }
}

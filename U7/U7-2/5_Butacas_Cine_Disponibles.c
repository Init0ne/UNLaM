//Butacas disponibles en una sala de cine

#include<stdio.h>
#include<stdlib.h>

void generador_MatrizEsquema(char [][9]);
void mostrar_Esquema(char [][9]);
int indice_Butaca(int);
int contar_Reservas(char [][9], int[], int[]);
int buscar_FilasVacias(int[], char[][9]);
void filas_MasOcupadas(int[]);
void mayor_MenorReservas(int[]);


int main()
{
    int f, b, pos, flag_Reserva, c_Reservas, c_Disponibles, c_FilasVacias,v_FilasVacias[12] = {0}, i, v_Filas[12] = {0}, v_Columnas[9] = {0};
    char m_Esquema[12][9];

    //Genera una matriz full 'D'
    generador_MatrizEsquema(m_Esquema);

    //Finaliza con f menor a 0
    do
    {
        //Muestra el esquema de butacas (Todas disponibles hasta ahora)
        mostrar_Esquema(m_Esquema);
        //Valida fila maxima
        do
        {
            //Ingresa el numero de fila deseado
            printf("\n Ingrese el numero de fila (o un numero negativo para finalizar) : ");
            scanf("%d", &f);
        } while (f > 12);
        //Si eligen una fila valida
        flag_Reserva = 0;
        if(f > 0)
        {
            do
            {
                //Ingresa el numero de butaca
                printf("\n Ingrese el numero de la butaca que desea reservar :");
                scanf("%d", &b);
                //Funcion busca el indice del numero de la butaca en vector
                pos = indice_Butaca(b);
                //Valida que la butaca este disponible
                if(m_Esquema[f-1][pos] == 'D')
                {
                    m_Esquema[f-1][pos] = 'R';
                    printf("\n Su reserva ha sido realizada, muchas gracias! \n");
                    flag_Reserva = 1;
                }
                else
                {
                    printf("\n Lo sentimos, la butaca que desea reservar ya ha sido ocupada, intentelo nuevamente! \n");
                }
            } while (flag_Reserva == 0);
        }
    } while (f > 0);

    //-------------------------------------------
    //Cantidad de D y R.
    c_Reservas = contar_Reservas(m_Esquema,v_Filas,v_Columnas);
    c_Disponibles = (12*9) - c_Reservas;
    printf("\n La cantidad de butacas reservadas fue de %d y la cantidad de disponibles %d \n", c_Reservas, c_Disponibles);
    //-------------------------------------------
    //Filas Vacias
    c_FilasVacias = buscar_FilasVacias(v_FilasVacias,m_Esquema);
    printf("\n Las filas que quedaron totalmente vacias fueron las siguientes : ");
    for(i = 0; i <= c_FilasVacias; i++)
    {
        printf("%3d", v_FilasVacias[i]);
    }
    printf("\n");
    //-------------------------------------------
    //La/s filas con mayor cantidad de espectadores
    printf("\n Las filas con mayor cantidad de espectadores son  la numero : ");
    filas_MasOcupadas(v_Filas);
    //-------------------------------------------
    //Muestra la lista de mayor a menor segun las reservas por columnas
    mayor_MenorReservas(v_Columnas);
    system("pause");
    return 0;
}

void generador_MatrizEsquema(char m_Esquema[][9])
{
    int i, j;

    for(i = 0; i < 12; i++ )
    {
        for(j = 0; j < 9; j++)
        {
            m_Esquema[i][j] = 'D';
        }
    }
}

void mostrar_Esquema(char m_Esquema[][9])
{
    int i,j, v[9] = {8,6,4,2,1,3,5,7,9};
    
    //Muestra numero de butacas
    for(i = 0; i < 9; i++)
    {
        printf("%4d", v[i]);
    }
    printf("\n\n");
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 9; j++)
        {
            printf("%4c", m_Esquema[i][j]);
        }
        printf("\n");
    }
}

int indice_Butaca(int b)
{
    int i, v[9] = {8,6,4,2,1,3,5,7,9};

    for(i = 0; i < 9; i++)
    {
        if(b == v[i])
        {
            return i;
        }
    }
}

int contar_Reservas(char m_Esquema[][9], int v_Filas[], int v_Columnas[])
{
    int i, j, cont_Reservas = 0;

    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(m_Esquema[i][j] == 'R')
            {
                cont_Reservas ++;
                v_Filas[i] ++;
                v_Columnas[j] ++;
            }
        }
    }
    return cont_Reservas;
}

int buscar_FilasVacias(int v_FilasVacias[], char m_Esquema[][9])
{
    int i, j, k, flag_Disponibles;
    k = -1;

    for(i = 0; i < 12; i++)
    {
        flag_Disponibles = 0;
        for(j = 0;j < 9; j++)
        {
            if(m_Esquema[i][j] == 'D')
            {
                flag_Disponibles ++;
                if(flag_Disponibles == 9)
                {
                    k++;
                    v_FilasVacias[k] = i+1;
                }
            }
        }
    }
    return k;
}

void filas_MasOcupadas(int v_Filas[])
{
    int i, f_Mayor = 0;
    
    for(i = 0; i < 12; i++)
    {
        if(v_Filas[i] > f_Mayor)
        {
            f_Mayor = v_Filas[i];
        }
    }
    for(i = 0; i < 12; i++)
    {
        if(f_Mayor == v_Filas[i])
        {
            printf("%d\t", i+1);
        }
    }
    printf("\n");
}

void mayor_MenorReservas(int v_Columnas[])
{
    int posmin,i, j, aux, aux1, v_Butacas[9] = {8,6,4,2,1,3,5,7,9};

    //Ordena los vectores por posicion de mayor a menor
    for(i = 0; i < 8; i++)
    {
        posmin = i;
        for(j = i + 1; j < 9; j++)
        {
            if(v_Columnas[j] > v_Columnas[posmin])
            {
                posmin = j;
            }
        }
        if(posmin != i)
        {
            aux = v_Columnas[i];
            aux1 = v_Butacas[i];
            v_Columnas[i] = v_Columnas[posmin];
            v_Butacas[i] = v_Butacas[posmin];
            v_Columnas[posmin] = aux;
            v_Butacas[posmin] = aux1;
        }
    }
    //Imprime ambos vectores ya ordenados
    printf("\tButaca \t\t Cantidad\n");
    for(i = 0; i < 9; i++)
    {
        printf("\t%3d \t\t %3d\n", v_Butacas[i], v_Columnas[i]);
    }
}


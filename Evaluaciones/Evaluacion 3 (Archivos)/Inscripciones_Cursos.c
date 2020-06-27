#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct 
{
    int cod;
    char descri[50];
    int cap;
    float price;
}cursos; 

typedef struct 
{
    char name[60];
    char email[50];
    int cod;
    int cant;
}solicitudes;

void leer_Texto(char [], int );
int menuPrincipal();
int contarRegistros(char[] );
void cargaCursos(char );

int main()
{
    int opc, valido;
    char carga;

    opc = menuPrincipal();

    while (opc != 5)
    {
        system("cls");
        switch (opc)
        {
        case 1:
            do
            {
                printf("\n [N] - Crear archivo nuevo");
                printf("\n [C] - Continuar con la carga");
                printf("\n\n Elija una opcion :  ");
                fflush(stdin);
                scanf("%c", &carga);
                fflush(stdin);
                carga = toupper(carga);
            } while (carga != 'N' && carga != 'C');
            cargaCursos(carga);
            break;

        case 2:
            break;

        case 3:
            break;
        
        case 4:
            break;
        
        case 5:
            printf("\n Hasta luego !");
            system("pause");
            break;

        default:
            printf("\n Ingrese una opcion correcta.");
            system("pause");
            break;

            system("cls");

            opc = menuPrincipal();
        }
    }

    system("pause");
    return 0;
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

int menuPrincipal()
{
    int opc;

    printf("\n \t\t\t\t --Menu principal--\n\n");
    printf("\n [1] - Carga de cursos");
    printf("\n [2] - Carga de inscripcion");
    printf("\n [3] - Listar ocupacion de cursos");
    printf("\n [4] - Generar reportes");
    printf("\n [5] - Salir");
    do
    {
        printf("\n\n Elija una opcion :  ");
        scanf("%d",&opc);
    } while (opc < 1 || opc > 5);

    return opc;
}

int contarRegistros(char name[]) // Contador de registros dentro de un archivo.
{
    int cont, read;
    cursos curso;
    FILE *arch;
    arch = fopen(name,"rb");
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    cont = 0;

    while (!feof(arch))
    {
        read = fread(&curso,sizeof(cursos),1,arch);
        if(read)
        {
            cont++;
        }
    }
    return cont;
}

void cargaCursos(char opcion)
{
    FILE *carga;
    int cont;
    char modo[3];
    cursos curso;

    if(opcion == 'N')
    {
        strcpy(modo,"wb");
        cont = 0;
    }
    else
    {
        strcpy(modo,"ab");
        cont = contarRegistros("CursoOfe.dat");
    }
    
    carga = fopen("CursoOfe.dat",modo);

    do
    {
        printf("\n Ingrese el codigo del curso entre 100 y 1000 (o 99 para finalizar la carga) :");
        scanf("%d",&curso.cod);
    } while (curso.cod < 99 || curso.cod > 1000);
    
    while(curso.cod != 99 && cont <= 20)
    {
        printf("\n Descripcion :");
        leer_Texto(curso.descri,50);

        do
        {
            printf("\n Capacidad :");
            scanf("%d",&curso.cap);
        } while (curso.cap > 50);
        
        printf("\n Precio :");
        scanf("%f",&curso.price);

        cont++;
        fwrite(&curso,sizeof(cursos),1,carga);

        //Nuevo comienzo de ciclo
        do
        {
            printf("\n Ingrese el codigo del curso entre 100 y 1000 (o 99 para finalizar la carga) :");
            scanf("%d",&curso.cod);
        } while (curso.cod < 99 || curso.cod > 1000);
    }
    fclose(carga);
}

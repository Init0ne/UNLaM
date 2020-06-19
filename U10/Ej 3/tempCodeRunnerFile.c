void mostrar_Archivo(productos prod)
{
    FILE *arch;
    arch = fopen("productos.dat","rb");
    //Se corrobora que no haya problemas
    if(arch == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&prod, sizeof(productos), 1, arch);
    //Mientras no llegue al final del archivo lee
    printf("\n Codigo \t Precio \t Desscripcion");
    while(!feof(arch))
    {
        printf("\n %5d \t\t $%10.2f \t %s", prod.cod, prod.precio, prod.descri );
        fread(&prod, sizeof(productos), 1, arch);
    }
    printf("\n");
    fclose(arch);
}
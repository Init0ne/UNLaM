FILE *alum;
    alum = fopen("alumnos.dat","rb");
    //Se corrobora que no haya problemas
    if(alum == NULL)
    {
        printf("\n Se produjo un error al abrir el archivo.");
        system("pause");
        exit(1);
    }
    fread(&al, sizeof(alumnos), 1, alum);
    //Mientras no llegue al final del archivo lee
    printf("\n DNI \t\t\t\t Nombre y Apellido \t Nota 1 \t Nota 2 \t Nota promedio \n\n");
    while(!feof(alum))
    {
        printf("\n %8d \t %30s \t %10d \t %10d \t %15.2f \n", al.dni,al.nombre_Apellido,al.nota[0],al.nota[1],al.nota_Promedio);
        fread(&al, sizeof(alumnos), 1, alum);
    }
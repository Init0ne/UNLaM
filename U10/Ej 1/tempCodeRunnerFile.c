printf("\n %8d \t %30s \t %10d \t %10d \t %15.2f \n", al.dni,al.nombre_Apellido,al.nota[0],al.nota[1],al.nota_Promedio);
        fread(&al, sizeof(alumnos), 1, alum);
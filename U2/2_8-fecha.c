#include<stdio.h>
#include<stdlib.h>
int main()
{
    int dd, mm, aa;

    printf("Ingrese el dia : ");
    scanf("%d", &dd);
    printf("Ingrese el mes : ");
    scanf("%d", &mm);
    printf("Ingrese el ano : ");
    scanf("%d", &aa);

    printf("\n %d %d %d \n", aa, mm, dd);

    getch();
    system("pause");
    return 0;
}

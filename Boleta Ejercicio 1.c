#include <stdio.h>


typedef struct {
    char nombre[50];
    char apellido_mat[50];
    char apellido_pat[50];
    int fecha;
    int numero;
    int adeudo;


} recibo;


int main() {


    int i,n;


    recibo agua[50];

    printf("Cuantos recibos desea emitir?: ");
    scanf("%i", &n);

    for(i=0;i<n;i++)
    {
    printf("\n\nRecibo no: %i\n\n", i + 1);

    printf("Introduce la fecha de emision: ");
    scanf("%d", agua[i].fecha);

    printf("Introduce el nombre deudor: ");
    scanf("%s", agua[i].nombre);

    printf("Introduce el apellido paterno del deudor: ");
    scanf("%s", agua[i].apellido_pat);

    printf("Introduce el apellido materno del deudor: ");
    scanf("%s", agua[i].apellido_mat);

    printf("Introduce codigo de cuenta: ");
    scanf("%d", &agua[i].numero);

    printf("Introduce la cantidad de adeudo: ");
    scanf("%d", &agua[i].adeudo);

    }

     for(i=0;i<n;i++)
    {
    printf("\n--- Recibo emitido no %i---\n",i + 1);

    printf("\n--- SIAPA---\n",i + 1);
    printf("Fecha de emision: %d\n", agua[i].fecha);
    printf("Nombre completo: %s %s %s\n", agua[i].nombre, agua[i].apellido_pat, agua[i].apellido_mat);
    printf("Codigo de cuenta: %d\n", agua[i].numero);
    printf("Adeudos totales: %d\n", agua[i].adeudo);

    }


    return 0;
}

#include <stdio.h>


typedef struct {
    char nombre[50];
    char apellido_mat[50];
    char apellido_pat[50];
    int numero;
    int adeudo;
    int energia;

} recibo;


int main() {


    int i,n;


    recibo electricidad[50];

    printf("Cuantos recibos desea emitir?: ");
    scanf("%i", &n);

    for(i=0;i<n;i++)
    {
    printf("\n\nRecibo no: %i\n\n", i + 1);

    printf("Introduce el nombre deudor: ");
    scanf("%s", electricidad[i].nombre);

    printf("Introduce el apellido paterno del deudor: ");
    scanf("%s", electricidad[i].apellido_pat);

    printf("Introduce el apellido materno del deudor: ");
    scanf("%s", electricidad[i].apellido_mat);

    printf("Introduce codigo de cuenta: ");
    scanf("%d", &electricidad[i].numero);

    printf("Introduce la cantidad de adeudo: ");
    scanf("%d", &electricidad[i].adeudo);

    printf("Introduce la cantidad de kWh gastados: ");
    scanf("%d", &electricidad[i].energia);

    }

     for(i=0;i<n;i++)
    {
    printf("\n--- Recibo emitido no %i---\n",i + 1);

    printf("\n--- CFE---\n",i + 1);

    printf("Nombre completo: %s %s %s\n", electricidad[i].nombre, electricidad[i].apellido_pat, electricidad[i].apellido_mat);
    printf("Codigo de cuenta: %d\n", electricidad[i].numero);
    printf("Adeudos totales: %d\n", electricidad[i].adeudo);
    printf("kWh totales gastados: %d\n", electricidad[i].energia);
    }


    return 0;
}

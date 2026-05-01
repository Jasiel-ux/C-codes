#include <stdio.h>

double convertir_gib(double cantidad, char unidad);

int main() {
    double cantidad;
    char unidad;

    printf("--- Conversor de Unidades Binarias ---\n");

    printf("Ingrese la cantidad en GiB: ");
    if (scanf("%lf", &cantidad) != 1) {
        printf("Error: Entrada no valida.\n");
        return 1;
    }

    printf("Seleccione unidad de destino (M para MiB, K para KiB): ");


    scanf(" %c", &unidad);

    double resultado = convertir_gib(cantidad, unidad);

    if (resultado != -1.0) {
        printf("\nResultado: %.4f GiB equivalen a %.2f %ciB\n",
                cantidad, resultado, (unidad == 'm' || unidad == 'M') ? 'M' : 'K');
    }

    return 0;
}

double convertir_gib(double cantidad, char unidad) {
    if (unidad == 'M' || unidad == 'm') {
        return cantidad * 1024.0;
    }
    else if (unidad == 'K' || unidad == 'k') {
        return cantidad * 1024.0 * 1024.0;
    }
    else {
        printf("Error: Unidad '%c' no valida.\n", unidad);
        return -1.0;
    }
}

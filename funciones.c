#include <stdio.h>
#include <stdlib.h>

void consultarSaldo(float saldo);
float depositar(float saldo, float cantidad);
float retirar(float saldo, float cantidad);

int main() {
    int opcion;
    float miSaldo = 1000.0;
    float monto;

    do {
        printf("\n--- CAJERO AUTOMATICO ---\n");
        printf("1. Consultar Saldo\n");
        printf("2. Depositar dinero\n");
        printf("3. Retirar dinero\n");
        printf("4. Historial\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                consultarSaldo(miSaldo);
                break;
            case 2:
                system("cls");
                printf("Ingrese cantidad a depositar: ");
                scanf("%f", &monto);
                miSaldo = depositar(miSaldo, monto);
                break;
            case 3:
                system("cls");
                printf("Ingrese cantidad a retirar: ");
                scanf("%f", &monto);
                miSaldo = retirar(miSaldo, monto);
                break;
            case 4:
                system("cls");
               printf("El historial de transacciones es el siguiente:\n");
               break;
            case 5:
                system("cls");
                printf("Gracias por usar nuestro sistema.\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}

void consultarSaldo(float saldo) {
    printf("Su saldo actual es: $%.2f\n", saldo);
}

float depositar(float saldo, float cantidad) {
    if (cantidad > 0) {
        system("cls");
        printf("Deposito exitoso.\n");
        return saldo + cantidad;
    }system("cls");
    printf("Cantidad invalida.\n");
    return saldo;
}

float retirar(float saldo, float cantidad) {
    if (cantidad <= saldo && cantidad > 0) {
        system("cls");
        printf("Retiro exitoso.\n");
        return saldo - cantidad;
    } else {
        system("cls");
        printf("Fondos insuficientes o cantidad invalida.\n");
        return saldo;
    }
}

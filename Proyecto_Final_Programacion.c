#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include <string.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#define ANCHO_CAJA 60
#define MAX_TRANSACCIONES 100
#define MAX_NOMBRE 50

typedef struct {
    char tipo[30];
    double monto;
    double saldo_resultante;
} transaccion;

typedef struct {
    char nombre[MAX_NOMBRE];
    double saldo;
    transaccion historial[MAX_TRANSACCIONES];
    int num_transacciones;
} usuario;

int gotoxy(int x, int y) {
    HANDLE hCon;
    COORD dwPos;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    dwPos.X = x;
    dwPos.Y = y;
    return SetConsoleCursorPosition(hCon, dwPos);
}

int registrar_transaccion(usuario *usu, const char *tipo, double monto) {
    if (usu->num_transacciones >= MAX_TRANSACCIONES) return 0;

    int indice = usu->num_transacciones;
    strcpy(usu->historial[indice].tipo, tipo);
    usu->historial[indice].monto = monto;
    usu->historial[indice].saldo_resultante = usu->saldo;
    usu->num_transacciones++;
    return 1;
}

void realizar_retiro(usuario *usu) {
    double monto;
    system("cls");
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|                    RETIRO DE DINERO                      |\n");
    printf("+----------------------------------------------------------+\n\n");

    printf("Saldo actual: $%.2f\n\n", usu->saldo);
    printf("Ingrese el monto a retirar: $");

    if (scanf("%lf", &monto) != 1) {
        printf("Error: Entrada invalida\n");
        while (getchar() != '\n');
        system("pause");
        return;
    }
    if (monto < 0.0) {
        printf("Error: el monto debe ser mayor a cero. ");
        system("pause");
        return;
    }
    if (monto > usu->saldo) {
        printf("Error: saldo insuficiente. Maximo a retirar: $%.2f\n", usu->saldo);
        system("pause");
        return;
    }
    usu->saldo -= monto;
    registrar_transaccion(usu, "Retiro", monto);

    printf("\nRetiro realizado exitosamente\n");
    printf("Nuevo saldo: $%.2f\n", usu->saldo);
    system("pause");
}

void realizar_deposito(usuario *usu) {
    double monto;
    system("cls");
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|                   DEPOSITO DE DINERO                     |\n");
    printf("+----------------------------------------------------------+\n\n");

    printf("Saldo actual: $%.2f\n\n", usu->saldo);
    printf("Ingrese el monto a depositar: $");

    if (scanf("%lf", &monto) != 1) {
        printf("Error: Entrada invalida\n");
        while (getchar() != '\n');
        system("pause");
        return;
    }
    if (monto <= 0.0) {
        printf("Error: el monto debe ser mayor a cero. ");
        system("pause");
        return;
    }
    usu->saldo += monto;
    registrar_transaccion(usu, "Deposito", monto);
    printf("\nDeposito realizado exitosamente\n");
    printf("Nuevo saldo: $%.2f\n", usu->saldo);
    system("pause");
}

void realizar_inversion(usuario *usu) {
    int opcion;
    double monto, ganancia, rendimiento;
    char tipo[30];

    system("cls");
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|                  OPCIONES DE INVERSION                   |\n");
    printf("+----------------------------------------------------------+\n\n");

    printf("Saldo actual: $%.2f\n\n", usu->saldo);
    printf("Seleccione una opcion: \n\n");
    printf("  1. Plazo Fijo (15%% anual) \n");
    printf("  2. CETES (12%% anual) \n");
    printf("  3. SOFIPO (8%% anual) \n");
    printf("  0. Cancelar\n\n");
    printf("opcion: ");

    if (scanf("%d", &opcion) != 1) {
        printf("Error: Entrada invalida\n");
        while (getchar() != '\n');
        system("pause");
        return;
    }
    switch (opcion) {
        case 1: rendimiento = 0.15; strcpy(tipo, "Plazo fijo (15%)"); break;
        case 2: rendimiento = 0.12; strcpy(tipo, "CETES (12%)"); break;
        case 3: rendimiento = 0.08; strcpy(tipo, "SOFIPO (8%)"); break;
        case 0: return;
        default: printf("Error: Opcion Invalida\n"); system("pause"); return;
    }

    printf("\nInvirtiendo en: %s\n", tipo);
    printf("Ingrese el monto a invertir: $");

    if (scanf("%lf", &monto) != 1|| monto <= 0.0) {
        printf("Error: monto invalido\n");
        while (getchar() != '\n');
        system("pause");
        return;
    }if (monto > usu->saldo ) {
        printf("Error: saldo insuficiente\n");
        system("pause");
        return;
    }

    ganancia = rendimiento * monto;
    usu->saldo += ganancia;
    registrar_transaccion(usu, tipo, ganancia);

    printf("\nInversion realizada exitosamente\n");
    printf("Nuevo saldo: $%.2f\n", usu->saldo);
    system("pause");
}

void mostrar_saldo_e_historial(usuario *usu) {
    int i;
    system("cls");
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|              CONSULTA DE SALDO E HISTORIAL               |\n");
    printf("+----------------------------------------------------------+\n\n");

    printf("SALDO ACTUAL: $%.2f\n\n", usu->saldo);

    if (usu->num_transacciones == 0) {
        printf("No hay transacciones registradas\n");
    }else {
        printf("HISTORIAL DE TRANSACCIONES:\n");
        printf("-----------------------------------------------------------\n");
        printf("%-25s | %-10s | %-13s\n", "Tipo", "Monto", "Saldo");
        printf("-----------------------------------------------------------\n");

        for (i = 0; i < usu->num_transacciones; i++) {
            printf("%-25s | $%-9.2f | $%-12.2f\n",
                   usu->historial[i].tipo,
                   usu->historial[i].monto,
                   usu->historial[i].saldo_resultante);
        }
        printf("-----------------------------------------------------------\n");
    }
    system("pause");
}

void mostrar_menu(int seleccion, usuario *usu) {
    int i;
    int centroX = 40;
    int centroY = 4;
    int posX = centroX - (ANCHO_CAJA / 2);

    system("cls");

    gotoxy(posX, centroY - 2);
    for (i = 0; i < ANCHO_CAJA; i++)  printf("-");

    gotoxy(posX, centroY - 1);
    printf("|                    CAJERO AUTOMATICO                     |\n");

    gotoxy(posX, centroY);
    printf("|  Bienvenido: %-42s  |\n", usu->nombre);

    gotoxy(posX, centroY + 1);
    printf("|  Saldo disponible: $%-33.2f    |\n", usu->saldo);

    gotoxy(posX, centroY + 2);
    for (i = 0; i < ANCHO_CAJA; i++) printf("-");

    gotoxy(posX, centroY + 3);
    printf("|                                                          |\n");

    gotoxy(posX, centroY + 4);
    printf("| %s  1. Retirar dinero                                    |\n", (seleccion == 1) ? "->" : "  ");

    gotoxy(posX, centroY + 5);
    printf("| %s  2. Depositar dinero                                  |\n", (seleccion == 2) ? "->" : "  ");

    gotoxy(posX, centroY + 6);
    printf("| %s  3. Invertir dinero                                   |\n", (seleccion == 3) ? "->" : "  ");

    gotoxy(posX, centroY + 7);
    printf("| %s  4. Consultar saldo e historial                       |\n", (seleccion == 4) ? "->" : "  ");

    gotoxy(posX, centroY + 8);
    printf("| %s  5. Salir                                             |\n", (seleccion == 5) ? "->" : "  ");

    gotoxy(posX, centroY + 9);
    printf("|                                                          |\n");

    gotoxy(posX, centroY + 10);
    for (i = 0; i < ANCHO_CAJA; i++) printf("-");

    gotoxy(posX, centroY + 11);
    printf("| Use las flechas ARRIBA/ABAJO y ENTER para seleccionar    |\n");

    gotoxy(posX, centroY + 12);
    for (i = 0; i < ANCHO_CAJA; i++) printf("-");
}

void pantalla_inicio(usuario *usu) {
    system("cls");
    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|            BIENVENIDO A SU CAJERO AUTOMATICO             |\n");
    printf("+----------------------------------------------------------+\n\n");

    printf("Por favor, ingrese sus datos:\n\n");
    printf("Nombre: ");
    scanf("%s", usu->nombre);

    printf("Dinero en su cuenta: $");
    if (scanf("%lf", &usu->saldo) != 1) usu->saldo = 0;
    if (usu->saldo < 0) usu->saldo = 0;

    usu->num_transacciones = 0;

    system("cls");
    printf("\n+----------------------------------------------------------+\n");
    printf("|       Sus datos han sido registrados exitosamente        |\n");
    printf("|                                                          |\n");
    printf("|  Nombre: %-48s|\n", usu->nombre);
    printf("|  Saldo: $%-48.2f|\n", usu->saldo);
    printf("|                                                          |\n");
    printf("|  Presione una tecla para continuar al menu...            |\n");
    printf("+----------------------------------------------------------+\n");
    getch();
}

int main() {

    setlocale(LC_ALL, "C");

    int seleccion = 1;
    char tecla;
    usuario mi_usuario;

    pantalla_inicio(&mi_usuario);

menu_inicio:
    mostrar_menu(seleccion, &mi_usuario);

    tecla = getch();

    if (tecla == ENTER) {
        switch (seleccion) {
            case 1: realizar_retiro (&mi_usuario); break;
            case 2: realizar_deposito (&mi_usuario); break;
            case 3: realizar_inversion (&mi_usuario); break;
            case 4: mostrar_saldo_e_historial (&mi_usuario); break;
            case 5:
                system("cls");
                printf("\n+----------------------------------------------------------+\n");
                printf("|             GRACIAS POR USAR NUESTRO CAJERO              |\n");
                printf("|                                                          |\n");
                printf("|  Hasta pronto, %-42s|\n", mi_usuario.nombre);
                printf("+----------------------------------------------------------+\n\n");
                system("pause");
                return 0;
        }
    } else if (tecla == -32 || tecla == 0) {
        tecla = getch();
        if (tecla == TECLA_ARRIBA) {
            seleccion --;
            if (seleccion < 1) seleccion = 5;
        } else if (tecla == TECLA_ABAJO) {
            seleccion ++;
            if (seleccion > 5) seleccion = 1;
        }
    } else {
        if (tecla == TECLA_ARRIBA) {
            seleccion --;
            if (seleccion < 1) seleccion = 5;
        }else if (tecla == TECLA_ABAJO) {
            seleccion ++;
            if (seleccion > 5) seleccion = 1;
        }
    }

    goto menu_inicio;
    return 0;
}

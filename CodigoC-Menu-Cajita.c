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

typedef struct{
    char tipo[30];
    double monto;
    double saldo_resultante;
} transaccion;

typedef struct {
    char nombre [MAX_NOMBRE];
    double saldo;
    transaccion historial[MAX_TRANSACCIONES];
    int num_transacciones;
} usuario;

int gotoxy(int )
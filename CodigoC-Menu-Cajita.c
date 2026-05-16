#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

// Prototipo de función para mover el cursor
void gotoxy(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos = {x, y};
    SetConsoleCursorPosition(hCon, dwPos);
}

// Función para dibujar una caja centrada para el contenido
void dibujarCajaContenido(int posX, int centroY, int ancho, char* titulo, char* mensaje) {
    int i;
    system("cls");

    // Borde superior
    gotoxy(posX, centroY - 2);
    for (i = 0; i < ancho; i++) printf("=");

    // Título
    gotoxy(posX, centroY - 1);
    printf("|| %*s%*s ||", (ancho - 4 + (int)strlen(titulo)) / 2, titulo, (ancho - 4 - (int)strlen(titulo)) / 2, "");

    // Espacio en blanco
    gotoxy(posX, centroY);
    printf("|| %*s ||", ancho - 4, "");

    // Mensaje/Contenido
    gotoxy(posX, centroY + 1);
    printf("|| %*s%*s ||", (ancho - 4 + (int)strlen(mensaje)) / 2, mensaje, (ancho - 4 - (int)strlen(mensaje)) / 2, "");

    // Instrucción para salir
    gotoxy(posX, centroY + 3);
    char* volver = "Presione cualquier tecla para VOLVER";
    printf("|| %*s%*s ||", (ancho - 4 + (int)strlen(volver)) / 2, volver, (ancho - 4 - (int)strlen(volver)) / 2, "");

    // Borde inferior
    gotoxy(posX, centroY + 4);
    for (i = 0; i < ancho; i++) printf("=");

    getch(); // Esperar tecla para volver
}

int main() {
    setlocale(LC_ALL, "");
    int seleccion = 1;
    char tecla;
    const int ANCHO_CAJA = 50;
    int i;

    // Variables de centrado
    int centroX = 40;
    int centroY = 8;
    int posX = centroX - (ANCHO_CAJA / 2);

menu_inicio:
    system("cls");

    // Dibujar Menú
    gotoxy(posX, centroY - 2);
    for (i = 0; i < ANCHO_CAJA; i++) printf("=");

    gotoxy(posX, centroY - 1);
    printf("||                  --- MENU ---                  ||\n");

    gotoxy(posX, centroY);
    printf("|| %s Opcion 1                                     ||\n", (seleccion == 1) ? "->" : "  ");
    gotoxy(posX, centroY + 1);
    printf("|| %s Opcion 2                                     ||\n", (seleccion == 2) ? "->" : "  ");
    gotoxy(posX, centroY + 2);
    printf("|| %s Opcion 3                                     ||\n", (seleccion == 3) ? "->" : "  ");
    gotoxy(posX, centroY + 3);
    printf("|| %s Opcion 4                                     ||\n", (seleccion == 4) ? "->" : "  ");
    gotoxy(posX, centroY + 4);
    printf("|| %s Salir                                        ||\n", (seleccion == 5) ? "->" : "  ");

    gotoxy(posX, centroY + 5);
    for (i = 0; i < ANCHO_CAJA; i++) printf("=");

    tecla = getch();

    if (tecla == ENTER) {
        switch (seleccion) {
            case 1:
                dibujarCajaContenido(posX, centroY, ANCHO_CAJA, "OPCION 1", "Ejecutando logica de la Opcion 1");
                break;
            case 2:
                dibujarCajaContenido(posX, centroY, ANCHO_CAJA, "OPCION 2", "Ejecutando logica de la Opcion 2");
                break;
            case 3:
                dibujarCajaContenido(posX, centroY, ANCHO_CAJA, "OPCION 3", "Ejecutando logica de la Opcion 3");
                break;
            case 4:
                dibujarCajaContenido(posX, centroY, ANCHO_CAJA, "OPCION 4", "Ejecutando logica de la Opcion 4");
                break;
            case 5:
                system("cls");
                printf("\n\n   Saliendo del programa...\n\n");
                Sleep(1000);
                exit(0);
        }
    } else {
        if (tecla == TECLA_ARRIBA) {
            seleccion--;
            if (seleccion < 1) seleccion = 5;
        } else if (tecla == TECLA_ABAJO) {
            seleccion++;
            if (seleccion > 5) seleccion = 1;
        }
    }

    goto menu_inicio;
    return 0;
}

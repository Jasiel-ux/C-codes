#include <stdio.h>


int verificar_paridad(unsigned char dato) {
    int contador = 0;

    for (int i = 0; i < 8; i++) {

        if ((dato >> i) & 1) {
            contador++;
        }
    }

    if (contador % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    unsigned int entrada;
    unsigned char dato;


    printf("Introduce un numero (0-255): ");

    if (scanf("%u", &entrada) != 1 || entrada > 255) {
        printf("Error: Por favor ingrese un numero valido entre 0 y 255.\n");
        return 1;
    }

    dato = (unsigned char)entrada;
    int resultado = verificar_paridad(dato);

    printf("El numero %u en binario tiene un numero %s de bits encendidos.\n",
            dato, (resultado == 1) ? "PAR" : "IMPAR");
    printf("Retorno de la funcion: %d\n", resultado);

    return 0;
}

#include <stdio.h>

typedef struct {
    char nombre[50];
    char apellido_pat[50];
    char apellido_mat[50];
    int numero;
} Contacto;

int main() {
    int i, n;

    Contacto lista[100];

    printf("¿Cuantos contactos deseas registrar? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\n--- Registro del contacto %d ---\n", i + 1);

        printf("Introduce el nombre: ");
        scanf("%s", lista[i].nombre);

        printf("Introduce el apellido paterno: ");
        scanf("%s", lista[i].apellido_pat);

        printf("Introduce el apellido materno: ");
        scanf("%s", lista[i].apellido_mat);

        printf("Introduce numero: ");
        scanf("%d", &lista[i].numero);

        printf("Introduce el correo: ");
        scanf("%s", lista[i].correo);
    }

    for(i = 0; i < n; i++) {
        printf("\n--- Datos del contacto %d ---\n", i + 1);
        printf("Nombre completo: %s %s %s\n", lista[i].nombre, lista[i].apellido_pat, lista[i].apellido_mat);
        printf("Numero: %d\n", lista[i].numero);
        printf("Correo: %s\n", lista[i].correo);
    }

    return 0;
}

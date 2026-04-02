#include <stdio.h>
#include <windows.h>

int main ()
{
    int ciclo_sem = 5;

    while(1)
    {
        printf("     +---------------+\n");
        printf("     |Verde -- Avance|\n");
        printf("     +---------------+\n\n");
        Sleep(ciclo_sem * 1000);

        printf("     +-----------------------+\n");
        printf("     |Amarillo -- Advertencia|\n");
        printf("     +-----------------------+\n\n");
        Sleep(ciclo_sem * 1000);


        printf("     +-----------------+\n");
        printf("     |Rojo -- Detengase|\n");
        printf("     +-----------------+\n\n");
        Sleep(ciclo_sem * 1000);
    }

    return 0;
}

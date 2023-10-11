#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    int opt, total_celdas, imprimir = 0;
    char *archivo_entrada = NULL, *archivo_salida = NULL;
    while ((opt = getopt(argc, argv, "N:i:o:D")) != -1)
    {
        switch (opt)
        {
        case 'N':
            total_celdas = atoi(optarg);
            break;

        case 'i':
            archivo_entrada = optarg;
            break;

        case 'o':
            archivo_salida = optarg;
            break;

        case 'D':
            imprimir = 1;
            break;
        }
    }

    // Si no se ingresa archivo de entrada y/o salida
    if (archivo_entrada == NULL || archivo_salida == NULL)
    {
        printf("Debe ingresar el nombre del archivo de entrada y de salida.\n");
        return 1;
    }

    manejarArchivos(archivo_entrada, archivo_salida, total_celdas, imprimir);

    return 0;
}
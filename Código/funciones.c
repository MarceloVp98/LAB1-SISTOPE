#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct particula
{
    int posicion_impacto;
    int energia;
} particulas;

double calculoEnergiaDepositada(int cantidad_celdas, int celda_impactada,
                                int posicion_celda_actual, int energia_potencial)
{
    double energia_depositada = (pow(10.0, 3.0) * energia_potencial) /
                                (cantidad_celdas * sqrt(fabs(celda_impactada - posicion_celda_actual) + 1));
    return energia_depositada;
}

double *calculoEnergiaDepositadaCeldas(particulas *particulas, int cantidad_celdas,
                                       int cantidad_particulas)
{
    double *energia_celdas = (double *)malloc(sizeof(double) * cantidad_celdas);
    if (energia_celdas == NULL)
    {
        // Manejo de error si no se pudo asignar memoria
        return NULL;
    }
    for (int i = 0; i < cantidad_celdas; ++i)
    {
        energia_celdas[i] = 0.0;
    }
    double energia_actual;
    for (int i = 0; i < cantidad_particulas; ++i)
    {
        for (int j = 0; j < cantidad_celdas; ++j)
        {
            energia_actual = calculoEnergiaDepositada(cantidad_celdas, particulas[i].posicion_impacto,
                                                      j, particulas[i].energia);
            if (energia_actual >= (pow(10.0, -3.0) / cantidad_celdas))
            {
                energia_celdas[j] = energia_celdas[j] + energia_actual;
            }
        }
    }
    for (int i = 0; i < cantidad_celdas; ++i)
    {
        printf("la energia de la calda %d es: %f.\n", i, energia_celdas[i]);
    }
    return energia_celdas;
}

int manejarArchivos(char *nombre_archivo_entrada, char *nombre_archivo_salida)
{
    FILE *archivo_entrada = fopen(nombre_archivo_entrada, "r");
    int numero_particulas;
    fscanf(archivo_entrada, "%d", &numero_particulas);
    particulas *particulas_leidas = (particulas *)malloc(sizeof(particulas) * numero_particulas);
    printf("la cantidad de particulas es: %d", numero_particulas);
    for (int i = 0; i < numero_particulas; ++i)
    {
        fscanf(archivo_entrada, "%d", &particulas_leidas[i].posicion_impacto);
        fscanf(archivo_entrada, "%d", &particulas_leidas[i].energia);
        printf("la particula %d impacto en la posicion %d y tiene una energia de %d\n",
               i, particulas_leidas[i].posicion_impacto, particulas_leidas[i].energia);
    }
    calculoEnergiaDepositadaCeldas(particulas_leidas, 35, numero_particulas);
    fclose(archivo_entrada);
    return 0;
}
#include "funciones.h"

double calculoEnergiaDepositada(float total_celdas, float celda_impactada,
                                float posicion_celda_actual, float energia_potencial)
{
    // Formula para calcular la energia de impacto.
    double energia_depositada = (pow(10.0, 3.0) * energia_potencial) /
                                (total_celdas * sqrt(fabs(celda_impactada - posicion_celda_actual) + 1));
    return energia_depositada;
}

double *calculoEnergiaDepositadaCeldas(particulas *particulas, int total_celdas,
                                       int cantidad_particulas)
{
    // Se crea el arreglo para almacenar la energia de las celdas.
    double *energia_celdas = (double *)malloc(sizeof(double) * total_celdas);
    if (energia_celdas == NULL)
    {
        // Manejo de error si no se pudo asignar memoria.
        return NULL;
    }
    // Se asigna 0.0 como energia a cada celda.
    for (int i = 0; i < total_celdas; ++i)
    {
        energia_celdas[i] = 0.0;
    }
    double energia_actual;
    // Se calcula y se suma la energia para cada una de las celdas.
    for (int i = 0; i < cantidad_particulas; ++i)
    {
        for (int j = 0; j < total_celdas; ++j)
        {
            energia_actual = calculoEnergiaDepositada(total_celdas, particulas[i].posicion_impacto,
                                                      j, particulas[i].energia);
            if (energia_actual >= (pow(10.0, -3.0) / total_celdas))
            {
                energia_celdas[j] = energia_celdas[j] + energia_actual;
            }
        }
    }
    return energia_celdas;
}

int celdaMayorEnergia(double *energia_celdas, int total_celdas)
{
    double mayor_energia = 0;
    int posicion;
    // Busquda de la celda con mayor energia.
    for (int i = 0; i < total_celdas; ++i)
    {
        if (energia_celdas[i] > mayor_energia)
        {
            mayor_energia = energia_celdas[i];
            posicion = i;
        }
    }
    return posicion + 1;
}

void imprimirGrafico(double *energia_celdas, int total_celdas, int celda_con_mayor_energia)
{
    double mayor_energia = energia_celdas[celda_con_mayor_energia];
    double cantidad_o;
    for (int i = 0; i < total_celdas; ++i)
    {
        printf("%d  %f |", i, energia_celdas[i]);
        // Se calcula la cantidad de O a imprimir segun la energia de la celda.
        //Se divide en 2 para que no sean tantas.
        cantidad_o = ((energia_celdas[i] / mayor_energia) * 100) / 2;
        for (double j = 0.0; j < cantidad_o; ++j)
        {
            printf("O");
        }
        printf("\n");
    }
}

void manejarArchivos(char *nombre_archivo_entrada, char *nombre_archivo_salida, int total_celdas, int imprimir)
{
    // Se abre el archivo de entrada.
    FILE *archivo_entrada = fopen(nombre_archivo_entrada, "r");
    int numero_particulas;
    // Se comienza la lectura del archivo y se asignan las variables correspondientes.
    fscanf(archivo_entrada, "%d", &numero_particulas);
    particulas *particulas_leidas = (particulas *)malloc(sizeof(particulas) * numero_particulas);
    for (int i = 0; i < numero_particulas; ++i)
    {
        fscanf(archivo_entrada, "%d", &particulas_leidas[i].posicion_impacto);
        fscanf(archivo_entrada, "%d", &particulas_leidas[i].energia);
    }
    // Se crea el archivo de salida.
    FILE *archivo_salida = fopen(nombre_archivo_salida, "w");
    double *energia_celdas = calculoEnergiaDepositadaCeldas(particulas_leidas, total_celdas, numero_particulas);
    int celda_con_mayor_energia = celdaMayorEnergia(energia_celdas, total_celdas);
    // Se comienza a escribir los datos de salida en el archivo.
    fprintf(archivo_salida, "%d ", celda_con_mayor_energia - 1);
    fprintf(archivo_salida, "%f\n", energia_celdas[celda_con_mayor_energia - 1]);
    for (int i = 0; i < total_celdas - 1; ++i)
    {
        fprintf(archivo_salida, "%d ", i);
        fprintf(archivo_salida, "%f\n", energia_celdas[i]);
    }
    fprintf(archivo_salida, "%d ", total_celdas - 1);
    fprintf(archivo_salida, "%f", energia_celdas[total_celdas - 1]);
    //Se verifica si se desea imprimir por pantalla o no el grafico.
    if (imprimir != 0)
    {
        imprimirGrafico(energia_celdas, total_celdas, celda_con_mayor_energia);
    }
    // Se cierran los archivos.
    fclose(archivo_salida);
    fclose(archivo_entrada);
    free(energia_celdas);
}
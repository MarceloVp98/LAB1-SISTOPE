#include "funciones.h"

typedef struct particula
{
    int posicion_impacto;
    int energia;
} particulas;


int calculoEnergiaDepositada(){
    return 0;
}

int leerArchivo(char *archivo_entrada)
{

    FILE *archivo = fopen(archivo_entrada, "r");
    int numero_particulas;
    fscanf(archivo, "%d", &numero_particulas);
    particulas *particulas_leidas = (particulas *)malloc(sizeof(particulas) * numero_particulas);
    printf("la cantidad de particulas es: %d", numero_particulas);
    for (int i = 0; i < numero_particulas; ++i)
    {
        fscanf(archivo, "%d", &particulas_leidas[i].posicion_impacto);
        fscanf(archivo, "%d", &particulas_leidas[i].energia);
        printf("la particula %d impacto en la posicion %d y tiene una energia de %d\n",
               i, particulas_leidas[i].posicion_impacto, particulas_leidas[i].energia);
    }
    fclose(archivo);
    return 0;
}
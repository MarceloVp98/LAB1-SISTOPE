#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "structParticula.c"

/*
ENTRADA: total_celdas(int) -> cantidad total de celdas del material.
         celda_impactada(int) -> numero de celda del material que impacto la particula.
         posicion_celda_actual(int) -> celda i del material.
         energia_potencial(int) -> energia potencial de la particula que impacto.
SALIDA:  energia_depositada(double) - > energia que deposito la particula en la celda i.
DESCRIPCION: Funcion que calcula la energia depositada sobre una celda i del material
             por una particula.
*/
double calculoEnergiaDepositada(int total_celdas, int celda_impactada,
                                int posicion_celda_actual, int energia_potencial);

/*
ENTRADA: particulas(particulas *) -> arreglo de struct particulas que contiene todos los
         datos del impacto de cada una de las particulas.
         total_celdas(int) -> cantidad total de celdas del material.
         cantidad_particulas(int) -> cantidad total de particulas que impactaron el material.
SALIDA:  energia_celdas(double *) - > arreglo con la energia de cada una de las celdas del material.
DESCRIPCION: Funcion que calcula la energia total de cada una de las celdas del material.
*/ 
double *calculoEnergiaDepositadaCeldas(particulas *particulas, int total_celdas,
                                       int cantidad_particulas);

/*
ENTRADA: energia_celdas(double *) -> arreglo que contiene la energia total de cada celda del material.
         total_celdas(int) -> cantidad total de celdas del material.
SALIDA:  posicion + 1(int) -> posicion de la celda con la mayor energia dentro del arreglo.
DESCRIPCION: Funcion que busca la celda con la mayor energia dentro del arrelo del celdas.
*/  
int celdaMayorEnergia(double *energia_celdas, int total_celdas);

/*
ENTRADA: energia_celdas(double *) -> arreglo que contiene la energia total de cada celda del material.
         celda_con_mayor_energia(int) -> posicion de la celda con mayor energia dentro del arreglo.
         total_celdas(int) -> cantidad total de celdas del material.
SALIDA:  vacio(void).
DESCRIPCION: Funcion que imprime un grafico normalizado del las energias de cada celda.
*/ 
void imprimirGrafico(double *energia_celdas, int total_celdas, int celda_con_mayor_energia);

/*
ENTRADA: nombre_archivo_entrada(char *) -> nombre del archivo a leer.
         nombre_archivo_salida(char *) -> nombre del archivo a escribir.
         total_celdas(int) -> cantidad total de celdas del material.
         imprimir(int) -> indica si se debe imprimir o no el grafico.
SALIDA:  vacio(void).
DESCRIPCION: Funcion que realiza la lectura y escritura de archivos.
*/  
void manejarArchivos(char *nombre_archivo_entrada, char *nombre_archivo_salida, int total_celdas, int imprimir);
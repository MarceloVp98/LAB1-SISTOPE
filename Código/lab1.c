#include "funciones.c"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int option, N, i, o, D;
    while (((option = getopt(argc, argv, "N:i:o:D")) != -1))
    {
        switch(option){
            case 'N':
                break;
            case 'i':
                break;
            case 'o':
                break;
            case 'D':
                break;
        }
    }
    manejarArchivos("entrada.txt", "archvivosalida.txt", 35);
    return 0;
}
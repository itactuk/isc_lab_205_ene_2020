//
// Created by Ivan's PC on 3/17/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "archivos_lib.h"

void guardar_perros(char * archivo, ARREGLO_PERRO arreglo_perros){
    int n = arreglo_perros.n;
    PERROS * perros = arreglo_perros.perros;
    FILE * p = fopen(archivo, "wb"); // wb para guardar y spbreescribir si existe

    fwrite(&n, sizeof(int), 1, p);
    fwrite(perros, sizeof(PERROS), n, p);

    for (int i = 0; i < n; ++i) {
        fwrite(&perros[i].n_amigos, sizeof(int), 1, p);
        fwrite(perros[i].amigos, sizeof(PERROS), perros[i].n_amigos, p);
    }
    fclose(p);
}

ARREGLO_PERRO leer_perros(char * archivo){

}
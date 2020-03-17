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
        // Aquí hay un problema con los amigos de los amigos del perro
        // ya que los punteros no se están guardando
        // Se podría resolver con recursividad,
        // pero estamos asumiendo que los amigos de los amigos no tienen amigos
        fwrite(perros[i].amigos, sizeof(PERROS), perros[i].n_amigos, p);
    }
    fclose(p);
}

ARREGLO_PERRO leer_perros(char * archivo){
    ARREGLO_PERRO arreglo_perros;
    int n;
    PERROS * perros;
    FILE * p = fopen(archivo, "rb"); // rb para leer un archivo

    fread(&n, sizeof(int), 1, p);
    perros = (PERROS*) malloc(n* sizeof(PERROS));
    fread(perros, sizeof(PERROS), n, p);

    for (int i = 0; i < n; ++i) {
        fread(&perros[i].n_amigos, sizeof(int), 1, p);
        // Aquí hay un problema con los amigos de los amigos del perro
        // ya que los punteros no se están guardando
        // Se podría resolver con recursividad,
        // pero estamos asumiendo que los amigos de los amigos no tienen amigos
        perros[i].amigos = (PERROS*) calloc(perros[i].n_amigos, sizeof(PERROS));
        fread(perros[i].amigos, sizeof(PERROS), perros[i].n_amigos, p);
    }
    fclose(p);
    arreglo_perros.n = n;
    arreglo_perros.perros = perros;
    return arreglo_perros;
}
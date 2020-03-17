//
// Created by Ivan's PC on 3/17/2020.
//

#ifndef ISC_LAB_205_ENE_2020_ARCHIVOS_LIB_H
#define ISC_LAB_205_ENE_2020_ARCHIVOS_LIB_H

typedef struct perros{
    char nombre[50];
    int edad;
    int n_amigos;
    struct perros * amigos;
} PERROS;

typedef struct arr_perros{
    PERROS * perros;
    int n;
} ARREGLO_PERRO;

ARREGLO_PERRO leer_perros(char * archivo);
void guardar_perros(char * archivo, ARREGLO_PERRO arreglo_perros);

#endif //ISC_LAB_205_ENE_2020_ARCHIVOS_LIB_H

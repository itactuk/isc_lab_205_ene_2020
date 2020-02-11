//
// Created by Ivan's PC on 2/11/2020.
//

#include "clase4Lib.h"


int contar_empleados_con_sal_may_50(double salarios[3], int n){
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        if (salarios[i] > 50){
            contador++;
        }
    }
    return contador;
}
void aumentar_salarios(double salarios[3], int n, double aumento){
    for (int i = 0; i < n; ++i) {
        salarios[i] += aumento;
    }
}
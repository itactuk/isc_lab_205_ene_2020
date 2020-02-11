//
// Created by Ivan's PC on 1/28/2020.
//

#include "CuadraticaLib.h"
#include <math.h>

float calc_delta(float a, float b, float c);

float calc_delta(float a, float b, float c){
    return sqrt(b*b - 4 * a *c);
}

float cuadratica_pos(float a, float b, float c){
    return (-b + calc_delta(a, b, c))/2.0*a;
}
float cuadratica_neg(float a, float b, float c){
    return (-b - calc_delta(a, b, c))/2.0*a;
}


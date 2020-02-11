//
// Created by Ivan's PC on 1/28/2020.
//
#include <stdio.h>
#include "CuadraticaLib.h"

int main(){
    float a, b, c;
    printf("Digite a: ");
    scanf("%f", &a);
    printf("\n");

    printf("Digite b: ");
    scanf("%f", &b);
    printf("\n");

    printf("Digite c: ");
    scanf("%f", &c);
    printf("\n");
    
    printf("x1=%f, x2=%f", cuadratica_pos(a, b, c), cuadratica_neg(a, b, c) );
}
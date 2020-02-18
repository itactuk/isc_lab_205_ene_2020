//
// Created by Ivan's PC on 2/18/2020.
//

#include "struct_lib.h"

float calc_pendiente(PUNTO p1, PUNTO p2){
    float res = (p2.y - p1.y) / (p2.x - p1.x);
    return res;
}
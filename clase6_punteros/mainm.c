//
// Created by Ivan's PC on 3/10/2020.
//
#include <stdlib.h>

int main(){
    int ** matriz;
    int m=3, n=4;
    matriz = (int**)malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i) {
        matriz[i] = (int *) malloc(n * sizeof(int));
    }
    // Todo eso de arriba equivale a int matr[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Digite el valor %d, %d de la matriz:", i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

}
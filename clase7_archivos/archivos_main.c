//
// Created by Ivan's PC on 3/17/2020.
//

#include <stdio.h>
#include <stdlib.h>

 int main(int n, char ** args){
    printf("Hello world %d", n);
     for (int i = 0; i < n; ++i) {
         printf("\nMi primer parametro es: %s", args[i]);
     }

     system("PAUSE");
}

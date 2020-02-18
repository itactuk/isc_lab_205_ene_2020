//
// Created by Ivan Tactuk on 2/18/2020.
//

#include <minunit.h>

#include "struct_lib.h"

#define MINUNIT_EPSILON 1E-6

MU_TEST(test_zero) {
    float resultado_esperado = 0.0;
    struct Punto p1 = {1.0, 2.0}; // Equivle a p1.x=1.0 y p1.y=2.0
    PUNTO p2;
    p2.x = 3.0;
    p2.y = 2.0;
    float resultado_obtenido = calc_pendiente(p1, p2);
    mu_assert_int_eq(resultado_esperado, resultado_obtenido);
}

MU_TEST(test_diff_zero) {
    float resultado_esperado = 1.0;
    struct Punto p1 = {1.0, 2.0}; // Equivle a p1.x=1.0 y p1.y=2.0
    PUNTO p2;
    p2.x = 2.0;
    p2.y = 3.0;
    float resultado_obtenido = calc_pendiente(p1, p2);
    mu_assert_int_eq(resultado_esperado, resultado_obtenido);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_zero);
    MU_RUN_TEST(test_diff_zero);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
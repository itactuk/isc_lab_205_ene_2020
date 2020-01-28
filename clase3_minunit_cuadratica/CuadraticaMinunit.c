//
// Created by Ivan Tactuk on 1/28/2020.
//

#include <minunit.h>

#include "CuadraticaLib.h"

#define MINUNIT_EPSILON 1E-1

MU_TEST(test_prueba_c0) {
    float a = 1.0, b = -2.0, c = 0;
    // Si tengo 1*x^2 - 2 * x + 0 = 0, entonces x1=2, x2=0
    // x= (-b +- raiz( b^2 - 4ac)) /2a ===  (2 +- raiz( 4 - 0))/ 2 = 1 +- 1 --> x1= 2, x2= 0
    float x1 = cuadratica_pos(a, b, c);
    float x2 = cuadratica_neg(a, b, c);

    mu_assert_double_eq(2.0, x1);
    mu_assert_double_eq(0.0, x2);
}

MU_TEST(test_prueba_b0) {
    float a = 1.0, b = 0.0, c = -4;
    // x^2 - 4 = 0; x1 = 2, x2 = -2
    float x1 = cuadratica_pos(a, b, c);
    float x2 = cuadratica_neg(a, b, c);

    mu_assert_double_eq(2.0, x1);
    mu_assert_double_eq(-2.0, x2);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_prueba_c0);
    MU_RUN_TEST(test_prueba_b0);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
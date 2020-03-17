//
// Created by Ivan Tactuk on 3/17/2020.
//

#include <minunit.h>

#include LIBRERIA_A_PROBAR

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_NombrePrueba) {
    mu_assert_int_eq(RESULTADO_ESPERADO, LLAMADA_FUNCION);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_NombrePrueba);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
//
// Created by Ivan Tactuk on 2/11/2020.
//

#include <minunit.h>

#include "clase4Lib.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_contar_emp) {
    double sal[3] = {1.2, 2.3, 53.3};
    int res = contar_empleados_con_sal_may_50(sal, 3);
    mu_assert_int_eq(1, res);
}

MU_TEST(test_aplicar_aumento) {
    double sal[3] = {1.2, 2.3, 53.3};
    aumentar_salarios(sal, 3, 2.0);
    mu_assert_double_eq(3.2, sal[0]);
    mu_assert_double_eq(5.3, sal[1]);
    mu_assert_double_eq(55.3, sal[2]);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_contar_emp);
    MU_RUN_TEST(test_aplicar_aumento);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
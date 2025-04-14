#include "quad.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void test_1() {
  double eps = 0;
  double a = 0;
  double b = 1;
  double c = -1;

  double *res = quad(a, b, c, eps);
  assert(res == NULL);
}

void test_2() {
  double eps = 0;
  double a = 1;
  double b = 0;
  double c = -1;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 2 && res[1] == -1 && res[2] == 1);
  free(res);
}

void test_3() {
  double eps = 0;
  double a = 1;
  double b = 0;
  double c = 0;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 1 && res[1] == 0);
  free(res);
}

void test_4() {
  double eps = 0;
  double a = 1;
  double b = 0;
  double c = 1;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 0);
  free(res);
}

void test_5() {
  double eps = 1E-7;
  double a = 1;
  double b = 0;
  double c = -1E-7;
  double eps_for_res = 1E-4;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 2 && fabs(res[1] + 3E-4) < eps_for_res &&
         fabs(res[2] - 3E-4) < eps_for_res);
  free(res);
}

void test_6() {
  double eps = 1E-11;
  double a = 1;
  double b = -1E+10;
  double c = -1;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 2 && fabs(res[1] + 1E-10) < eps &&
         fabs(res[2] - 1E+10) < eps);
  free(res);
}

void test_7() {
  double eps = 1E-7;
  double a = 1;
  double b = 0;
  double c = -1E-8;

  double *res = quad(a, b, c, eps);
  assert(res[0] == 1 && res[1] < eps);
  free(res);
}

int main() {
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  return 0;
}
#include "quad.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int quad(double a, double b, double c, double eps, double **result) {
  if (fabs(a) <= eps) {
    *result = NULL;
    return NOT_A_QUAD;
  }

  b = b / a;
  c = c / a;
  a = 1;

  double desc = (b * b) - (4 * c);

  if (desc < -eps) {
    *result = NULL;
    return NO_R_ROOTS;
  }

  if (desc > eps) {
    double x1;
    double x2;

    int sgn;
    if (b >= eps) {
      sgn = -1;
    }

    else {
      sgn = 1;
    }

    x1 = (-1 * b + sqrt(desc) * sgn) / 2;
    x2 = c / x1;

    if (x1 > x2) {
      double svo = x1;
      x1 = x2;
      x2 = svo;
    }

    *result = (double *)malloc(sizeof(double) * 2);
    (*result)[0] = x1;
    (*result)[1] = x2;

    return TWO_ROOTS;
  } else if (fabs(desc) <= eps) {
    *result = (double *)malloc(sizeof(double) * 1);

    double x1 = (-b) / 2;

    if (fabs(x1) == 0)
      x1 = fabs(x1);

    (*result)[0] = x1;

    return ONE_ROOT;
  }
}

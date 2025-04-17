#include "quad.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *quad(double a, double b, double c, double eps) {
  if (fabs(a) <= eps)
    return NULL;

  b = b / a;
  c = c / a;
  a = 1;

  double desc = (b * b) - (4 * c);

  if (desc < -eps) {
    double *result = malloc(sizeof(double));
    result[0] = 0;
    return result;
  }

  if (desc > eps) {
    double *result;
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

    result = malloc(sizeof(double) * 3);
    result[0] = 2;
    result[1] = x1;
    result[2] = x2;

    return result;
  } else if (fabs(desc) <= eps) {
    double *result = malloc(sizeof(double) * 2);

    double x1 = (-b) / 2;

    if (fabs(x1) == 0)
      x1 = fabs(x1);

    result[0] = 1;
    result[1] = x1;

    return result;
  }
}
#include "quad.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *quad(double a, double b, double c, double eps) {
  if (fabs(a) <= eps)
    return NULL;
  const double Eps = 0.0002;

  b = b / a;
  c = c / a;
  a = 1;

  double desc = (b * b) - (4 * c);

  if (desc > 0) {
    double *result;
    double x1;
    double x2;
    if (b >= 0) {
      x1 = (-1 * b - sqrt(desc)) / 2;
    }

    else {
      x1 = (-1 * b + sqrt(desc)) / 2;
    }

    x2 = c / x1;

    if (x1 > x2) {
      double svo = x1;
      x1 = x2;
      x2 = svo;
    }

    if (fabs(x1 - x2) <= Eps) {
      result = malloc(sizeof(double) * 2);
      result[0] = 1;
      result[1] = (x1 + x2) / 2;
    } else {
      result = malloc(sizeof(double) * 3);
      result[0] = 2;
      result[1] = x1;
      result[2] = x2;
    }

    return result;
  } else if (fabs(desc) <= eps) {
    double *result = malloc(sizeof(double) * 2);

    double x1 = (-b) / 2 * a;

    if (fabs(x1) == 0)
      x1 = fabs(x1);

    result[0] = 1;
    result[1] = x1;

    return result;
  }
  double *altRes = malloc(sizeof(double));
  altRes[0] = 0;
  return altRes;
}
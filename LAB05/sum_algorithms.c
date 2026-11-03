#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

double do_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   for (long i = 0; i < ncells; i++){
      sum += var[i];
   }
   return sum;
}

double do_long_double_sum(double* restrict var, long ncells)
{
    long double sum = 0.0L;

    for (long i = 0; i < ncells; i++) {
        sum += (long double)var[i];
    }

    return (double)sum;
}
double do_pairwise_sum(double* restrict var, long ncells)
{
    if (ncells == 0) {
        return 0.0;
    }

    if (ncells == 1) {
        return var[0];
    }

    long middle = ncells / 2;

    double left = do_pairwise_sum(var, middle);
    double right = do_pairwise_sum(var + middle, ncells - middle);

    return left + right;
}
double do_kahan_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    double c = 0.0;

    for (long i = 0; i < ncells; i++) {
        double y = var[i] - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return sum;
}
double do_knuth_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    double correction = 0.0;

    for (long i = 0; i < ncells; i++) {
        double a = sum;
        double b = var[i];

        double s = a + b;
        double z = s - a;

        double error = (a - (s - z)) + (b - z);

        sum = s;
        correction += error;
    }

    return sum + correction;
}

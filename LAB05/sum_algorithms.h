#ifndef SUM_ALGORITHMS_H
#define SUM_ALGORITHMS_H

/*
 * Standard double precision sum
 */
double do_sum(double* restrict var, long ncells);

/*
 * Long double precision sum
*/
double do_long_double_sum(double* restrict var, long ncells);
/*
 * Pairwise summation
 */
double do_pairwise_sum(double* restrict var, long ncells);
/*
 * Kahan summation
 */
double do_kahan_sum(double* restrict var, long ncells);
/*
 * Knuth summation
 */
double do_knuth_sum(double* restrict var, long ncells);

#endif //SUM_ALGORITHMS_H

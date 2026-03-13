#ifndef MY_MATH_H
#define MY_MATH_H

// Function declarations
double my_pow(double base, int exp);
double my_fabs(double nbr);
double my_sqrt(double S);
double compute_discr(double a, double b, double c);
void solve_quadratic(double a, double b, double c,
                     double *x1, double *x2, int *num_roots);

#endif

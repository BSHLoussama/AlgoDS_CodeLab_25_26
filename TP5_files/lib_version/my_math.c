#include <stdio.h>
#include "my_math.h"

// Your functions go here

double my_pow(double base, int exp) {
    if (exp < 0) {
        printf("Error: this version only handles positive exponents\n");
        return -1;
    }
    if (base == 0 && exp == 0) {
        printf("Error: 0^0 is undefined\n");
        return -1;
    }

    double result = 1.0;
    for (int i = 0; i < exp; i++)
        result *= base;

    return result;
}

double my_fabs(double nbr) {
    return (nbr < 0) ? -nbr : nbr;
}

double my_sqrt(double S) {
    if (S < 0) {
        printf("Error: Negative number!\n");
        return -1;
    }
    if (S == 0) return 0;

    double x = S;
    double prev;
    double epsilon = 1e-10;
    do {
        prev = x;
        x = (x + S / x) / 2;
    } while (my_fabs(x - prev) > epsilon);
    return x;
}

double compute_discr(double a, double b, double c) {
    return my_pow(b, 2) - 4 * a * c;
}

void solve_quadratic(double a, double b, double c,
                     double *x1, double *x2, int *num_roots) {
    if (a == 0) {
        printf("Not a quadratic equation (a = 0)\n");
        *num_roots = -1;
    } else {
        double delta = compute_discr(a, b, c);

        if (delta > 0) {
            double sqrt_delta = my_sqrt(delta);
            printf("Two Solutions, delta = %.1f > 0\n", delta);
            *x1 = (-b - sqrt_delta) / (2 * a);
            *x2 = (-b + sqrt_delta) / (2 * a);
            *num_roots = 2;
        } else if (delta < 0) {
            printf("No Real Solutions, delta = %.1f < 0\n", delta);
            *x1 = *x2 = 0;
            *num_roots = 0;
        } else {
            printf("Delta = 0.0, double root\n");
            *x1 = *x2 = -b / (2 * a);
            *num_roots = 1;
        }
    }
}

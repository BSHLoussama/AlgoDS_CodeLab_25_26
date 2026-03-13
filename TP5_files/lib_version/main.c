#include <stdio.h>
#include "my_math.h"

int main() {
    double x1, x2;
    int roots;

    solve_quadratic(1, -3, 2, &x1, &x2, &roots);

    if (roots == 2)
        printf("x1 = %.5f, x2 = %.5f\n", x1, x2);
    else if (roots == 1)
        printf("x = %.5f\n", x1);
    else
        printf("No real solution.\n");

    return 0;
}

// it has to contain only one main
// gcc main.c my_math.c -o my_program -lm
// gcc *.c -o my_program -lm

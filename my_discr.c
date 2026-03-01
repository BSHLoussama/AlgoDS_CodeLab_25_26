#include <stdio.h>

double my_pow(double base, int exp);
double compute_discr(double a, double b, double c);

int main()
{
    printf("delta = %.2lf\n", compute_discr(1, 2, -3));
    return 0;
}

double my_pow(double base, int exp)
{
    if (exp < 0)
    {
        printf("Error: this version only handles positive exponents\n");
        return -1;
    }

    if (base == 0 && exp == 0)
    {
        printf("Error: 0^0 is undefined\n");
        return -1;
    }

    double result = 1.0;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }

    return result;
}


//DRY
double compute_discr(double a, double b, double c)
{
    double delta = my_pow(b, 2) - 4 * a * c;
    return delta;
}


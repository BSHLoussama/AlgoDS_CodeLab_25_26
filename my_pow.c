#include <stdio.h>

double my_pow(double base, int exp);

int main()
{
    double base = 2;
    int exp = 5;

    // double result = my_pow(base, exp);
    if (my_pow(base, exp) != -1)
        printf("\n%.1lf ^ %d = %.5lf\n", base, exp, my_pow(base, exp));

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
        result = result * base;
        //result *= base;

    return result;
}



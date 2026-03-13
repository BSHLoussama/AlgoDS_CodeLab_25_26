#include <stdio.h>
#include <math.h>

double my_fabs(double nbr);
double my_sqrt(double S);

int main() 
{
	
    double test_list[] = {0, 1, 2, 25, -5};  // Let compiler count size
    int size = sizeof(test_list) / sizeof(test_list[0]);
    
	int i;
    for (i = 0; i < size; i++) {
        double t_nbr = test_list[i];

        printf("my_sqrt(%.2lf) = %.10lf \t sqrt(%.2lf) = %.10lf\n",
               t_nbr, my_sqrt(t_nbr),
               t_nbr, sqrt(t_nbr));
    }

	double nbr = -15;
    if (my_sqrt(nbr) != -1)
        printf("Square root of %.10lf is %.10lf\n", nbr, my_sqrt(nbr));

    return 0;
}

double my_fabs(double nbr)
{
    // return (nbr < 0) ? -nbr : nbr;
    if (nbr < 0) return -nbr;
    else return nbr;
}

double my_sqrt(double S)
{
    if (S < 0) {
        printf("Error: Negative number!\n");
        return -1;
    }

    if (S == 0)
        return 0;  // Prevent division by zero

    double x = S;          // Initial guess
    double prev;
    double epsilon = 1e-10;

    do {
        prev = x;
        x = (x + S / x) / 2;
    } while (my_fabs(x - prev) > epsilon);

    return x;
}

//gcc mysqrt.c -o mysqrt -lm



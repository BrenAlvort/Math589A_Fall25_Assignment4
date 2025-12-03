#include <stdio.h>
#include "fixed_point.h"

int main(void)
{
    double x1, x2;
    int iters;
    double scale = 0.1;

    int rc = fixed_point_solve(0.5, 0.5, 1e-6, 1000, &x1, &x2, &iters, scale);

    if (rc == 0) {
        printf("Converged:\n");
        printf("  x1 = %.10f\n", x1);
        printf("  x2 = %.10f\n", x2);
        printf("  iterations = %d\n", iters);
    } else if (rc == 1) {
        printf("Did not converge after %d iterations.\n", iters);
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}

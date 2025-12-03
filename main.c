#include <stdio.h>
#include "fixed_point.h"

int main(void)
{
    double x1, x2;
    int iters;

    int rc = fixed_point_solve(0.5, 0.5, 1e-6, 1000, &x1, &x2, &iters, 0.1);

    if (rc == 0) {
        printf("Converged in %d iterations\n", iters);
        printf("x1 = %.10f, x2 = %.10f\n", x1, x2);
    } else if (rc == 1) {
        printf("Did not converge\n");
    } else {
        printf("Invalid input\n");
    }
    return 0;
}

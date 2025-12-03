#include "fixed_point.h"
#include <math.h>
#include <stddef.h>

int fixed_point_solve(double x1_0, double x2_0, double tol, int max_iter,
                      double *x1_out, double *x2_out, int *iters_out, double scale)
{
    if (tol <= 0.0 || max_iter <= 0 ||
        x1_out == NULL || x2_out == NULL || iters_out == NULL)
    {
        return -1;
    }

    double x1 = x1_0;
    double x2 = x2_0;

    for (int k = 0; k < max_iter; k++) {

        double x1_new = exp(-x1) + scale * x2;
        double x2_new = cos(x2) + scale * x1;

        double d1 = fabs(x1_new - x1);
        double d2 = fabs(x2_new - x2);
        double err = (d1 > d2 ? d1 : d2);

        x1 = x1_new;
        x2 = x2_new;

        if (err < tol) {
            *x1_out = x1;
            *x2_out = x2;
            *iters_out = k + 1;
            return 0;
        }
    }

    *x1_out = x1;
    *x2_out = x2;
    *iters_out = max_iter;
    return 1;
}

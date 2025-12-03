#include "fixed_point.h"
#include <math.h>

int fixed_point_solve(double x1_0, double x2_0, double tol, int max_iter,
                      double *x1_out, double *x2_out, int *iters_out, double scale)
{
    /* --- validate input --- */
    if (tol <= 0.0 || max_iter <= 0 || 
        x1_out == NULL || x2_out == NULL || iters_out == NULL)
    {
        return -1; /* invalid input */
    }

    double x1 = x1_0;
    double x2 = x2_0;

    for (int k = 0; k < max_iter; k++) {

        /* Fixed-point update */
        double x1_new = exp(-x1) + scale * x2;
        double x2_new = cos(x2) + scale * x1;

        /* Compute error = max(|Δx1|,|Δx2|) */
        double diff1 = fabs(x1_new - x1);
        double diff2 = fabs(x2_new - x2);
        double err = (diff1 > diff2 ? diff1 : diff2);

        /* Update values */
        x1 = x1_new;
        x2 = x2_new;

        /* Converged */
        if (err < tol) {
            *x1_out = x1;
            *x2_out = x2;
            *iters_out = k + 1;
            return 0; /* success */
        }
    }

    /* Not converged */
    *x1_out = x1;
    *x2_out = x2;
    *iters_out = max_iter;
    return 1; /* reached iteration limit */
}

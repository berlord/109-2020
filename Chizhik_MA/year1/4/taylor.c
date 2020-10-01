#include <stdio.h>
#include <math.h>

#include "../lib/umath.h"
#include "taylor.h"

double taylor_recurrent(double x, double precision, int *n, Status *s, dFUNC start_value, diFUNC recurrence) {
	double comp_value, taylor_addendum;

	*n = 1;
	*s = OK;

	comp_value = (*start_value)(x);
	taylor_addendum = (*start_value)(x) * (*recurrence)(x, *n);

	while (compareDoubles(taylor_addendum, 0, precision / 4) != 0) {
		comp_value += taylor_addendum;
		if (*n > 100) {
			*s = TOO_LONG;
			return comp_value;
		}

		*n += 1;
		taylor_addendum *= (*recurrence)(x, *n);
	}

	return comp_value;
}

double one(double x) {
	return 1 + 0 * x;
}

double linear(double x, int n) {
	return x / n;
}

double taylor_exp(double x, double precision, int *n, Status *s) {
	return taylor_recurrent(x, precision, n, s, one, linear);
}


double id(double x) {
	return x;
}

double sin_square(double x, int n) {
	return -x * x / (2 * n * (2 * n + 1));
}

double taylor_sin(double x, double precision, int *n, Status *s) {
        return taylor_recurrent(x, precision, n, s, id, sin_square);
}


double cos_square(double x, int n) {
	return -x * x / ((2 * n - 1) * 2 * n);
}

double taylor_cos(double x, double precision, int *n, Status *s) {
        return taylor_recurrent(x, precision, n, s, one, cos_square);
}


double taylor_log(double x, double precision, int *n, Status *s) {
        double real_x = x - 1;
        double comp_value, taylor_addendum;
        *s = OK;
	*n = 1;

	if (compareDoubles(x, 0, precision) != 1) {
                *s = BAD_VALUE;
                return 0;
        }

        comp_value = real_x;
        taylor_addendum = -real_x * real_x / 2;

        while (compareDoubles(taylor_addendum, 0, precision / 4) != 0) {
		comp_value += taylor_addendum;
                if (*n > 50) {
                        *s = TOO_LONG;  
                        return comp_value;
                }

                *n += 1;

		taylor_addendum *= (-real_x) * (*n) / ((*n) + 1);
        }

        return comp_value;
}

//Using these functions you can compute values far from zero with quite a high accuracy

double effective_taylor_exp(double x, double precision, int *n, Status *s) {
	int floor;
	double sum, decimal_part;
	
	floor = (int)x;
	decimal_part = x - floor;

	sum = pow(M_E, floor);
	
	if (floor > 100) {
		*s = TOO_BIG;
		return sum;
	}

	sum *= taylor_exp(decimal_part, precision, n, s);
	return sum;
}

double effective_taylor_sin(double x, double precision, int *n, Status *s) {
	double new_x = x;
	int floor, sign = 1;
	if (new_x < 0) {
		sign *= -1;
		new_x *= -1;
	}

	floor = (int)(new_x / (2 * M_PI));
	new_x -= floor * 2 * M_PI;
	if (new_x > M_PI) {
		new_x -= 2 * M_PI;
		new_x *= -1;
		sign *= -1;
	}

	return sign * taylor_sin(new_x, precision, n, s);
}

double effective_taylor_cos(double x, double precision, int *n, Status *s) {
	double new_x = x;
	int floor;

	if (new_x < 0) {
		new_x *= -1;
	}

	floor = (int)(new_x / (2 * M_PI));
	new_x -= floor * 2 * M_PI;
	if (new_x > M_PI) {
		new_x -= 2 * M_PI;
		new_x *= -1;
	}

	return taylor_cos(new_x, precision, n, s);
}

double effective_taylor_log(double x, double precision, int *n, Status *s) {
	const double sqrt_e = 1.648721271;
	double new_x = x;
	int pow = 0;
	*s = OK;

	if (compareDoubles(new_x, 0, precision) != 1) {
		*s = BAD_VALUE;
		return 0;
	}

	while (new_x > 1.65) {
		new_x /= sqrt_e;
		pow++;
	}

	return ((double)pow / 2) + taylor_log(new_x, precision, n, s);
}

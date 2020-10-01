#include <stdio.h>
#include <math.h>

#include "simpson.h"
#include "../lib/umath.h"

/*
 * Подсчет интегральной суммы для фиксироанного разбиения
 *
 * Параметры:
 * f: вещественнозначная функция от одной переменной, от которой считается интеграл
 * a: левый конец отрезка
 * b: правый конец отрезка
 * n: количество подотрезков равной длины, на которые разбит исходный отрезок [a, b]
 *
 * Функция считает интегральную сумму для f по формуле Симпсона с заданным 
 * равномерным разбиением отрезка [a, b] на n подотрезков.
 *
 */

static double integration_with_fixed_step(dFUNC f, double a, double b, int n) {
	double step, x, sum;
	int i, coefficient;

	step = (b - a) / n;
	sum = (*f)(a) + (*f)(b);
	x = a + step;

	for (i = 1; i < n; i++) {
		coefficient = (i % 2 == 0) ? 2 : 4;
		sum += (*f)(x) * coefficient;
		x += step;
	}

	return step * sum / 3;
}

double simpson_integral(dFUNC f, double a, double b, double precision, IntStatus *s) {
	double current_i, prev_i;
	double swap;
	int n, sign = 1;
	*s = OK_INT;

	if (a > b) {
		swap = a;
		a = b;
		b = swap;
		sign *= -1;
	}

	prev_i = integration_with_fixed_step(f, a, b, 2);

	for (n = 4; n < 1e8; n *= 2) {
		current_i = integration_with_fixed_step(f, a, b, n);
		if (compareDoubles(current_i, prev_i, precision) == 0) {
			return current_i * sign;
		}
		prev_i = current_i;
	}

	*s = METHOD_DOES_NOT_CONVERGE;
	return current_i * sign;
}

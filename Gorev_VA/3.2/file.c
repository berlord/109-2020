#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 0.00001

double Min(double(*f) (double), double a, double b, int* Error);
double Min(double(*f) (double), double a, double b, int* Error)
{
	double x0, x1, x2, f0, f1, f2;
	int q;
	if (a > b)
	{
		x1 = a;
		a = b;
		b = x1;
	}
	x0 = b - (b - a) * (sqrt(5) - 1) * 0.5;
	q = 1;

	for (int i = 1; i <= 1000; i++)
	{
		if (q)
			x1 = a + (b - a) * (sqrt(5) - 1) * 0.5;
		else
			x0 = b - (b - a) * (sqrt(5) - 1) * 0.5;

		if ((*f)(x0) >= (*f)(x1))
		{
			a = x0;
			x0 = x1;
			q = 1; // �� ��������� ���� ����� ������� �1
		}
		else
		{
			b = x1;
			x1 = x0;
			q = 0; // �� ��������� ���� ����� ������� �0
		}
		printf("  %f %f %f %f\n", a, x0, x1, b);
		if ((b - a) < eps)
			break;
	}

	if ((b - a) >= eps)
	{
		*Error = 1;
		return 0.0;
	}
	else
	{
		x0 = a;
		x1 = b;
		x2 = (a + b) * 0.5;
		f0 = (*f)(x0);
		f1 = (*f)(x1);
		f2 = (*f)(x2);
		printf(" %f %f %f  %f %f %f\n", x0, x1, x2, f0, f1, f2);
		//printf("    %f %f", x2 * x2 * f0 - x0 * x0 * f2 + x0 * x0 * f1 - x1 * x1 * f0 + x1 * x1 * f2 - x2 * x2 * f1, f2 * x0 - f0 * x2 + f0 * x1 - f1 * x0 + f1 * x2 - f2 * x1);
		a = (x2 * x2 * f0 - x0 * x0 * f2 + x0 * x0 * f1 - x1 * x1 * f0 + x1 * x1 * f2 - x2 * x2 * f1);
		b = (f2 * x0 - f0 * x2 + f0 * x1 - f1 * x0 + f1 * x2 - f2 * x1);
		a = (double)a / (double)b;
		a *= 0.5;
		printf("    %f %f\n", a, x1 - x0);
		*Error = 0;
		return a;
	}
}

double F1(double x);
double F1(double x)
{
	return x * x * x - x;
}

int main(void)
{
	int* Error;
	Error = (int*)malloc(1 * sizeof(int));
	printf("%f\n", Min(F1, 0.0, 2.0, Error));
	return 0;
}
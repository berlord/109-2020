#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "f.h"
double f1 (double x)
{
	return x*x + 5*x - 6;
}
double f2 (double x)
{
	return x*x + 1;
}
double f3 (double x)
{
	return x*x*x;
}
double f4 (double x)
{
	return (x - 5)*(x - 6)*(x - 7);
}
int main(void)
{
	double a = -4, b = 2, eps = 0.0001, m;
	ErrorCode err;
	m = root(f1, a, b, eps, &err);
	
	printf("x*x + 5*x - 6 = 0 ");
	switch(err)
	{
	case ROOT_NOT:
        printf("FAULT\n");
		break;
	case ROOT_OK:
		m = root(f1, a, b, eps, NULL);
		printf("Answer = %e\n", m);
	}
	
	printf("x*x + 1 = 0 ");
	m = root(f2, a, b, eps, &err);
	switch(err)
	{
	case ROOT_NOT:
        printf("FAULT\n");
		break;
	case ROOT_OK:
		m = root(f2, a, b, eps, NULL);
		printf("Answer = %e\n", m);
	}
	
	printf("x*x*x = 0 ");
	m = root(f3, a, b, eps, &err);
	switch(err)
	{
	case ROOT_NOT:
        printf("FAULT\n");
		break;
	case ROOT_OK:
		m = root(f3, a, b, eps, NULL);
		printf("Answer = %e\n", m);
	}
	
	printf("x*x + 8*x = 0 ");
	m = root(f4, a, b, eps, &err);
	switch(err)
	{
		case ROOT_NOT:
			printf("FAULT\n");
			break;
		case ROOT_OK:
			m = root(f4, a, b, eps, NULL);
			printf("Answer = %e\n", m);
	}
	return 0;
}



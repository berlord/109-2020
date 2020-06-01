#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "11.h"
static double simp(double a, double b, double ep, RRFUN ffunc);

double delenie(double a, double b, double ep, RRFUN1 func, ErrorCode *error_code)
{
	double kon1 = a, ser = 0, kon2 = b, res1 = 0, ser1 = 0, res2 = 0;
	double dlina = b - a;
	ser = (a + b)/2;
	res1 = (*func)(kon1);
	res2 = (*func)(kon2);
	*error_code = SF_OK;
	if(res1*res2 >= 0) 
	{
		*error_code = SF_ERROR;
		return 0;
	}
	while(dlina > ep)
	{
		ser = (kon1 + kon2)/2;
		ser1 = (*func)(ser);
		if(ser1*res1 <= 0)
		{
			kon2 = ser;
			res2 = ser1;
		}
		if (ser1*res1 > 0)
		{
			kon1 = ser;
			res1 = ser1;
		}
		dlina = kon2 - kon1;
	}
	return (kon1 + kon2)/2;
}

double integrate(double a, double b, double ep, RRFUN ffunc)
{
	int n = 2;
	double i1 = simp(a, b, n, ffunc), i2 = simp(a, b, 2*n, ffunc);
	while ((n > 0) && (modul(i2 - i1) > ep) && (n < 67108864))
	{                                              
		i1 = simp(a, b, n, ffunc);
		n = 2*n;
		i2 = simp(a, b, n, ffunc);
	}
	return i2;
}

static double simp(double a, double b, double n, RRFUN ffunc)
{
	int i;
	double h = 0, res1 = 0, res2 = 0, res = 0, x = 0, i1 = 0, i2 = 0, k = 1;
	h = (b-a)/(2*n);
	for(i = 1; i < n-1; i++)
	{
		x = a+2*i*h;
		res1 = res1 + (*ffunc)(x, b);
	}
	for(i = 1; i < n; i++)
	{
		x = a+(2*i-1)*h;
		res2 = res2 + (*ffunc)(x, b);
	}
	res = (h/3)*(2*res1 + 4*res2 + (*ffunc)(a, b) + (*ffunc)(b, b));
	return res;
}

double modul(double x)
{
	if (x < 0)
		return -x;
	else 
		return x;
}
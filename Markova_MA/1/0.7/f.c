#include "f.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void a (long double (*f)(long double), int (*g)(long double, long double), double x)
{
	long double ans = (*f)(x), k;
	int check = 0;
	printf("%Le ", ans);
	printf("%Le", (*f)(ans));
	k = (*g)(ans, (*f)(ans));
	while(k != 0)
	{
		check++;
		ans = (*f)(ans);
		printf(", %Le", ans);
		k = (*g)(ans, (*f)(ans));
		if (check > T)
		{
			printf("error ");
			break;
		}
	}
	printf("\n");
}

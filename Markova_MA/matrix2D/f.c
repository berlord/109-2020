#include "f.h"


void print_matrix(double *a, int n, int m) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			printf("%10.3e ", a[i*m + j]);
		printf("\n");
	}
	printf("\n");
}

void ERROR_RE(int ret) {
	switch (ret)
	{
		case ERROR_OPEN:
			printf("Cannot open \n");
		case ERROR_READ:
			printf("Cannot read \n");
	}
}

void ved_null(double *a, int n, int m, int ii, int jj, double max) {
	int i;
	double ved = a[jj * m + ii];
	for(i = ii; i < m; ++i)
		a[jj*m + i] -= (a[ii*m +i] / max) * ved;
}

void share (double *a, int n, int m, int i, double max)
{
	for(int t = n; t < m; t++)
	{
		a[i*m + t] /= max;
	}
}


void change_str(double *a, int n, int m, int i, int j) {
	int k; double tmp;
	for(k = 0; k < m; ++k) {
		tmp = a[i*m + k]; 
		a[i*m + k] = a[j*m + k]; 
		a[j*m + k] = tmp;
	}
}

int matr(double *a, int n, int m, double eps) {
	int i, j, pos, res = n;
	double max, help;
	for(i = 0; i < n; ++i) {
		j = i + 1;
		max = a[i*m + i];
		pos = i;
		if(fabs(max) < eps){
		for( ;j < n; j++)
		{
			help = a[j*m + i];
			if(fabs(help) > eps)
			{
				pos = j;
				max = help;
			}
		}
		}
		
		printf("%d ", pos);
		
 		/*if(fabs(max) <= eps) {
			res = 0;
			return res;
 		}
*/
		if(i != pos)
			change_str(a, n, m, i, pos);
		max = a[i*m + i];
		print_matrix(a, n, m);
		for(j = i + 1; j < n; ++j)
		{
			printf("ya");
			ved_null(a, n, m, i, j, max);
		}
	}
	
	print_matrix(a, n, m);
	
	if(fabs(a[(n - 1)*m + n - 1]) <= eps)
	{
		res = 0;
		return res;
	}
	
	
	for(i = n - 1; i >= 0;i--)
	{
		max = a[i*m + i];
		for(j = i - 1; j >= 0; j--)
		{
			ved_null(a, n, m, i, j, max);
		}
	}
	for(i = 0;i < n;i++)
	{
		max = a[i*m + i];
		share(a, n, m, i, max);
		a[i*m + i] = 1;
	}
	return 1;
}

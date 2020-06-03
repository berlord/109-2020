#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#include "MaxEl.h"
#include "prn_matr.h"
void solve(double *a, int n, int m)
{
	int NumMaxPos = choose_string(a, n, m);
	printf("NumMaxPos: %d\n", NumMaxPos);
	PoelMax(a, n, m, NumMaxPos);
}
	
int choose_string(double *a, int n, int m)
{ 
	int MaxElinStr, PosMaxEl, MaxPos = 0, NumMaxPos = 0;
	for (int i = 0; i < n; i++)
	{
		MaxElinStr = a[i*m];
		PosMaxEl = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i*m+ j] >= MaxElinStr)
			{
				MaxElinStr = a[i*m+j];
				PosMaxEl = j;
			}
		}
		if (PosMaxEl >= MaxPos)
		{
			MaxPos = PosMaxEl;
			NumMaxPos = i;
		}
	}
	return NumMaxPos;
}
void PoelMax(double *a, int n, int m, int NumMaxPos)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i*m+j] < a[NumMaxPos*m+j])
				a[i*m+j] = a[NumMaxPos*m+j];
		}
	}
}
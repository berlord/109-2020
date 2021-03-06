#include <stdio.h>
#include "back.h"
#include <math.h>
#include <stdlib.h>

void swap(double **a, double **b);
void swap(double **a, double **b) {
    double *c;
    c = *a;
    *a = *b;
    *b = c;
}

void print(double **matr, int n) {
    for(int j = 0; j < n; j++)	{
	    for(int k = 0; k < n; k++)
		    printf("%lf ", matr[k][j]);
        printf("\n");
	}
}

double **obr(double **matrix, int n, double eps, int *indicator) {
    // indicator = 1, если матрица обращается, а 0 если матрица вырождена
    int k, j, i;
	double c;
    double **matr, **newmatr;
    *indicator = 1;
    matr = malloc(n * sizeof(double *));
    newmatr = malloc(n * sizeof(double *));
    for(j = 0; j < n; j++) {
	    matr[j] = malloc(n * sizeof(double));
        newmatr[j] = malloc(n * sizeof(double));
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            matr[i][j] = matrix[i][j];
            if(i == j)
                newmatr[i][j] = 1;
            else
                newmatr[i][j] = 0;
        }
    }
    for(j = 0; j < n; j++) {
            k = -1;
            for(i = j; i < n; i++) {
                if(fabs(matr[i][j]) > eps) {
                    k = i;
                    break;  
                }         
            }
            if(k == -1) {
                    *indicator = 0;
                    return matr;
            }
            if(k != j) {
                swap(&matr[j], &matr[k]);
                swap(&newmatr[j], &newmatr[k]);
            }
            for(i = j + 1; i < n; i++) {
                    c = matr[i][j] / matr[j][j];
                    for(int t = 0; t < n; t++) {
                        matr[i][t] -= matr[j][t] * c;
                        newmatr[i][t] -= newmatr[j][t] * c;
                    }        
            }   
    }
    for(i = 0; i < n; i++) {
        c = matr[i][i];
        if(fabs(c) > eps) {
            for(j = 0; j < n; j++) {
                matr[i][j] /= c;
                newmatr[i][j] /= c;
            }
        } 
    }
    for(j = n - 1; j > 0; j--) { 
        for(i = j - 1; i >= 0; i--) {
            for(k = 0; k < n; k++) {
                newmatr[i][k] -= newmatr[j][k] * matr[i][j]; 
            }
            matr[i][j] = 0; 
        }
    }
    for(j = 0; j < n; j++) {
	    free(matr[j]);
    }
    free(matr);
    return newmatr;  
}

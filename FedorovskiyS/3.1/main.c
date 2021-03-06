#include <stdio.h>
#include <math.h>
#include "min.h"

double f0(double x);
//double f1(double x);
//double f2(double x);

double f0(double x){
    return (x*x - 2.)*(x*x - 2.);
}

/*double f1(double x){
    return x - 9./8;
}*/

/*double f0(double x){
    return (x-1)*(x-1);
}*/
//ответы: 0; нет минимумов; 0;
int main(void){
    ErrCode err;
    double a = -2, b = 2, eps = 1e-6, s;
    s = min(f0, eps, a, b, &err);
    if(err == NO_MIN)
        printf("No min\n");
    else
        printf("%lf\n", s);
    return 0;
}


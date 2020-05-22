#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "point.h"

const double g=9.81;
const double v0=0;
const double alpha=0;
const double xi0=10.0,yi0=10.0;
int i=0;
double x,y;

void delay_100ms(){
    clock_t t0, t1 ;
    t0 = clock();
    do{
        t1 = clock();
    }while ((t1 -t0) <= (CLOCKS_PER_SEC/10));
}

double trajectoire_X(double t){
    double x;
    x=v0*cos(alpha)*t+xi0;
    return x;
}

double trajectoire_Y(double t){
    double y;
    y=(-1/2)*g*pow(t,2)+v0*sin(alpha)*t+yi0;
    return y;
}

int main(){
    for(i=0;i<10;i++){
        trajectoire_X(0);
        trajectoire_Y(0);
        printf("x : %f ",&x);
        printf("y : %f \n",&y);
        delay_100ms();
    }
}

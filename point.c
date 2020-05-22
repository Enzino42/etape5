#include <stdio.h>
#include "point.h"

double coefx;
double coefy;
const int resolutionX = 800;
const int resolutionY = 600;


const point PO ={0,6,0,0}; // repere en bas a gauche
//const point PO ={-4,3,0,0}; // repere au mileu

//repere en metres
const double X_max = 8.0;
const double Y_max = 6.0;

void print_point(point p){
    printf("\ncoordonnees du point en m :\nx:%lf  y:%lf\ncoordonnees du point en px :\nx:%d  y:%d",p.xm,p.ym,p.xpx,p.ypx);
}

point init_point(point p, double x, double y){
    p.xm=x;
    p.ym=y;
    p=XYmTopx(p);
    return p;
}

point placer_pointX(point p, double x){
    p.xm=x;
    p=XYpxTom(p);
    return p;
}

point placer_pointY(point p, double y){
    p.ym=y;
    p=XYpxTom(p);
    return p;
}

point placer_pointXY(point p, double x, double y){
    p.xm=x;
    p.ym=y;
    p=XYpxTom(p);
    return p;
}

point deplacer_pointXY(point p,double dx,double dy){
    p.xm=p.xm+dx;
    p.ym=p.ym+dy;
    p=XYmTopx(p);
    return p;
}

point XYmTopx(point p){
    coefx=resolutionX/X_max;
    coefy=resolutionY/Y_max;
    p.xpx = (((p.xm)-(PO.xm))*coefx);
    p.ypx = (((-p.ym)+(PO.ym))*coefy);
    return p;
}

point XYpxTom(point p){
    coefx=resolutionX/X_max;
    coefy=resolutionY/Y_max;
    p.xm = (PO.xm+(p.xpx/coefx));
    p.ym = (PO.ym-(p.ypx/coefy));
    return p;
}

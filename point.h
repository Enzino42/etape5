#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


typedef struct {
    double xi0,yi0,alpha,v0,ym,xm,ytraj,xtraj;
    int xpx,ypx;
} point ;

//fonction :
extern point XYmTopx(point);//
extern point XYpxTom(point);// convertisseurs
extern void print_point(point);// affiche les parametre d'un point
extern point init_point(point,double,double);//initialise un pointavec les valeur math�matique
extern point placer_pointX(point, double); //place un point a la coordon� xm
extern point placer_pointY(point,double); //place un point a la coordon� ym
extern point placer_pointXY(point,double,double);//place un point coordoner xm ym
extern point deplacer_pointXY(point,double,double);//depalce un point de dx dy

#endif

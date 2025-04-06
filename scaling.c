#include "fractol.h"


double plane_x(int win_x,int width){
    double x;
    double scalar;
    scalar = 4.0 / width;
    x = -2.0 + win_x * scalar;
    return x;
}

double plane_y(int win_y,int height){
    double y;
    double scalar;
    scalar = 4.0 / height;
    y = 2.0 - win_y * scalar;
    return y;
}


int window_x(double plane_x, int width)
{
    int x;
    double scalar;  
    scalar = width / 4.0;
    x = (int)((2.0 + plane_x) * scalar);  
    return x;
}

int window_y(double plane_y, int height)
{
    int y;
    double scalar; 
    scalar = height / 4.0;
    y = (int)((2.0 - plane_y) * scalar);  
    return y;
}
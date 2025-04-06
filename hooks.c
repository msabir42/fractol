#include "fractol.h"

int close_key(int key, t_fractal *fractal){
    if (key == KEYSUM){
        mlx_destroy_window(fractal->mlx,fractal->w);
        exit(0);
    }
    return (0);
}

int close_key_julia(int key, t_julia *julia){
    if (key == KEYSUM){
        mlx_destroy_window(julia->mlx,julia->w);
        exit(0);
    }
    return (0);
}
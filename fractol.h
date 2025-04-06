#ifndef FRACTOL_H

#define FRACTOL_H

#include<unistd.h>
#include"mlx/mlx.h"
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <stdio.h>
#define HEIGHT  2000
#define WIDTH 2000
#define MAX_ITERATIONS 100
# define KEYSUM 65307 

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_complex{
    double real;
    double imaginary;
} t_complex;

typedef struct s_fractal {
    void *mlx;
    void *w;
    t_data data;
} t_fractal;

typedef struct s_julia {
    void *mlx;
    void *w;
    t_data data;
    t_complex c;
} t_julia;


void init_mandelbrot(t_fractal *fract);
void init_mandelbrot(t_fractal* fract);
int close_key(int key, t_fractal *fractal);
t_complex init_complex(double real, double imaginary);
int mandelbrot_iterations(t_complex* c);
void render_mandelbrot(t_fractal *fract);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void putstr(char* s);
int ft_atoi(char *s);
void print_error();
double plane_x(int win_x,int width);
double plane_y(int win_y,int height);
int window_x(double plane_x, int width);
int window_y(double plane_y, int height);
int get_color(int iterations, int max_iterations);
void init_julia(t_julia *julia, double c_real, double c_imag);
int close_key_julia(int key, t_julia *julia);
void render_julia(t_julia *julia);

#endif
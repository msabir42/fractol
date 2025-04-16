/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:45:39 by msabir            #+#    #+#             */
/*   Updated: 2025/04/12 14:21:33 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define HEIGHT 1000
# define WIDTH 1000
# define MAX_ITERATIONS 100
# define KEYSUM 65307

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_content
{
	double		z_real_squared;
	double		z_imag_squared;
	double		new_real;
	double		new_imaginary;
}				t_content;

typedef struct s_fractal
{
	void		*mlx;
	void		*w;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
	double		zoom;
	t_complex	c;
	t_data		data;
}				t_fractal;

typedef struct s_julia
{
	void		*mlx;
	void		*w;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
	double		zoom;
	t_data		data;
	t_complex	c;
}				t_julia;

int				handle_mandelbrot(void);
int				handle_julia(int argc, char **argv);
void			init_mandelbrot(t_fractal *fract);
void			init_mandelbrot(t_fractal *fract);
int				close_key(int key, t_fractal *fractal);
t_complex		init_complex(double real, double imaginary);
int				mandelbrot_iterations(t_complex *c);
void			render_mandelbrot(t_fractal *fract);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_putstr(char *s);
int				ft_atoi(const char *nptr);
void			print_error(void);
int				is_valid_float(const char *str);
int				has_valid_sign(const char *str);
int				check_bounds(double input1, double input2);
int				ft_isdigit(int c);
double			plane_x(int win_x, int width, double min_x, double max_x);
double			plane_y(int win_y, int height, double min_y, double max_y);
int				get_color(int iterations, int max_iterations);
void			init_julia(t_julia *julia, double c_real, double c_imag);
int				close_key_julia(int key, t_julia *julia);
void			render_julia(t_julia *julia);
void			set_bounds(t_fractal *fract);
void			set_bounds_julia(t_julia *julia);
int				mouse_zoom_mandelbrot(int key, int x, int y, t_fractal *fract);
int				mouse_zoom_julia(int key, int x, int y, t_julia *fract);
void			destroy_mlx(t_fractal *fract);
void			destroy_window(t_fractal *fract);
void			destroy_image(t_fractal *fract);
void			destroy_mlx_julia(t_julia *julia);
void			destroy_window_julia(t_julia *julia);
void			destroy_image_julia(t_julia *julia);
double			ft_atof(const char *str);
int				ft_strlen(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_isdigit(int c);
int				close_key(int key, t_fractal *fractal);
int				close_mandelbrot(t_fractal *fractal);
void			cleanup_mandelbrot(t_fractal *fractal);
void			cleanup_julia(t_julia *julia);
int				close_julia(t_julia *julia);
#endif

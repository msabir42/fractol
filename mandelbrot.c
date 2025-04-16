/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:08 by msabir            #+#    #+#             */
/*   Updated: 2025/04/10 18:40:59 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(t_complex *c)
{
	t_complex	z;
	int			iter;
	double		z_real_squared;
	double		z_imag_squared;
	double		temp_real;

	z = init_complex(0, 0);
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		z_real_squared = z.real * z.real;
		z_imag_squared = z.imaginary * z.imaginary;
		if (z_real_squared + z_imag_squared > 4.0)
			break ;
		temp_real = z_real_squared - z_imag_squared + c->real;
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = temp_real;
		iter++;
	}
	return (iter);
}

int	get_color(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iterations)
		return (0x000000);
	t = (double)iterations / max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	render_mandelbrot(t_fractal *fract)
{
	t_complex	c;
	int			color;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = plane_x(x, WIDTH, fract->min_x, fract->max_x);
			c.imaginary = plane_y(y, HEIGHT, fract->min_y, fract->max_y);
			color = get_color(mandelbrot_iterations(&c), MAX_ITERATIONS);
			my_mlx_pixel_put(&fract->data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->mlx, fract->w, fract->data.img, 0, 0);
}

void	init_mandelbrot(t_fractal *fract)
{
	fract->mlx = mlx_init();
	if (fract->mlx == NULL)
		destroy_mlx(fract);
	fract->w = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (fract->w == NULL)
		destroy_window(fract);
	fract->data.img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	if (fract->data.img == NULL)
		destroy_image(fract);
	fract->data.addr = mlx_get_data_addr(fract->data.img,
			&fract->data.bits_per_pixel,
			&fract->data.line_length,
			&fract->data.endian);
	set_bounds(fract);
	render_mandelbrot(fract);
	mlx_key_hook(fract->w, close_key, fract);
	mlx_mouse_hook(fract->w, mouse_zoom_mandelbrot, fract);
	mlx_hook(fract->w, 17, 0, close_mandelbrot, fract);
	mlx_loop(fract->mlx);
}

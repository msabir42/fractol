/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:48 by msabir            #+#    #+#             */
/*   Updated: 2025/04/10 18:37:26 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_julia *julia, double c_real, double c_imag)
{
	julia->mlx = mlx_init();
	if (julia->mlx == NULL)
		destroy_mlx_julia(julia);
	julia->w = mlx_new_window(julia->mlx, WIDTH, HEIGHT, "Julia");
	if (julia->w == NULL)
		destroy_window_julia(julia);
	julia->data.img = mlx_new_image(julia->mlx, WIDTH, HEIGHT);
	if (julia->data.img == NULL)
		destroy_image_julia(julia);
	julia->data.addr = mlx_get_data_addr(julia->data.img,
			&julia->data.bits_per_pixel,
			&julia->data.line_length,
			&julia->data.endian);
	set_bounds_julia(julia);
	julia->c.real = c_real;
	julia->c.imaginary = c_imag;
	render_julia(julia);
	mlx_key_hook(julia->w, close_key_julia, julia);
	mlx_hook(julia->w, 17, 0, close_julia, julia);
	mlx_mouse_hook(julia->w, mouse_zoom_julia, julia);
	mlx_loop(julia->mlx);
}

int	julia_iterations(t_complex point, t_complex c)
{
	t_complex	z;
	int			iter;
	t_content	t;

	z = point;
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		t.z_real_squared = z.real * z.real;
		t.z_imag_squared = z.imaginary * z.imaginary;
		if (t.z_real_squared + t.z_imag_squared > 4.0)
			break ;
		t.new_real = t.z_real_squared - t.z_imag_squared + c.real;
		t.new_imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = t.new_real;
		z.imaginary = t.new_imaginary;
		iter++;
	}
	return (iter);
}

void	render_julia(t_julia *julia)
{
	t_complex	point;
	t_complex	c;
	int			x;
	int			y;
	int			color;

	c = julia->c;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			point.real = plane_x(x, WIDTH, julia->min_x, julia->max_x);
			point.imaginary = plane_y(y, HEIGHT, julia->min_y, julia->max_y);
			color = get_color(julia_iterations(point, c), MAX_ITERATIONS);
			my_mlx_pixel_put(&julia->data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(julia->mlx, julia->w, julia->data.img, 0, 0);
}

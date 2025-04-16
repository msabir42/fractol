/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:35 by msabir            #+#    #+#             */
/*   Updated: 2025/04/09 13:46:36 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom_mandelbrot(int key, int x, int y, t_fractal *fract)
{
	double	new_x;
	double	new_y;
	double	new_width;
	double	new_height;
	double	zoom_scalar;

	new_x = plane_x(x, WIDTH, fract->min_x, fract->max_x);
	new_y = plane_y(y, HEIGHT, fract->min_y, fract->max_y);
	if (key == 4)
		zoom_scalar = 0.9;
	else if (key == 5)
		zoom_scalar = 1.1;
	else
		return (0);
	new_width = (fract->max_x - fract->min_x) * zoom_scalar;
	new_height = (fract->max_y - fract->min_y) * zoom_scalar;
	fract->min_x = new_x - (new_width / 2);
	fract->max_x = new_x + (new_width / 2);
	fract->min_y = new_y - (new_height / 2);
	fract->max_y = new_y + (new_height / 2);
	fract->zoom *= (1.0 / zoom_scalar);
	render_mandelbrot(fract);
	return (0);
}

int	mouse_zoom_julia(int key, int x, int y, t_julia *fract)
{
	double	new_x;
	double	new_y;
	double	new_width;
	double	new_height;
	double	zoom_scalar;

	new_x = plane_x(x, WIDTH, fract->min_x, fract->max_x);
	new_y = plane_y(y, HEIGHT, fract->min_y, fract->max_y);
	if (key == 4)
		zoom_scalar = 0.9;
	else if (key == 5)
		zoom_scalar = 1.1;
	else
		return (0);
	new_width = (fract->max_x - fract->min_x) * zoom_scalar;
	new_height = (fract->max_y - fract->min_y) * zoom_scalar;
	fract->min_x = new_x - (new_width / 2);
	fract->max_x = new_x + (new_width / 2);
	fract->min_y = new_y - (new_height / 2);
	fract->max_y = new_y + (new_height / 2);
	fract->zoom *= (1.0 / zoom_scalar);
	render_julia(fract);
	return (0);
}

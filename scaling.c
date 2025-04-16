/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:15 by msabir            #+#    #+#             */
/*   Updated: 2025/04/10 12:09:34 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	plane_x(int win_x, int width, double min_x, double max_x)
{
	double	x;
	double	scalar;

	scalar = (max_x - min_x) / width;
	x = min_x + win_x * scalar;
	return (x);
}

double	plane_y(int win_y, int height, double min_y, double max_y)
{
	double	y;
	double	scalar;

	scalar = (max_y - min_y) / height;
	y = min_y + win_y * scalar;
	return (y);
}

void	set_bounds(t_fractal *fract)
{
	fract->min_x = -2.0;
	fract->max_x = 2.0;
	fract->min_y = -2.0;
	fract->max_y = 2.0;
	fract->zoom = 1.0;
}

void	set_bounds_julia(t_julia *julia)
{
	julia->min_x = -2.0;
	julia->max_x = 2.0;
	julia->min_y = 2.0;
	julia->max_y = -2.0;
	julia->zoom = 1.0;
}

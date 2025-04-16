/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:03:26 by msabir            #+#    #+#             */
/*   Updated: 2025/04/09 20:05:53 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_key(int key, t_fractal *fractal)
{
	if (key == KEYSUM)
	{
		cleanup_mandelbrot(fractal);
		exit(0);
	}
	return (0);
}

void	cleanup_mandelbrot(t_fractal *fractal)
{
	if (fractal->data.img)
		mlx_destroy_image(fractal->mlx, fractal->data.img);
	if (fractal->w)
		mlx_destroy_window(fractal->mlx, fractal->w);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	free(fractal);
}

int	close_mandelbrot(t_fractal *fractal)
{
	cleanup_mandelbrot(fractal);
	exit(0);
	return (0);
}

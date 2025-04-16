/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:46:42 by msabir            #+#    #+#             */
/*   Updated: 2025/04/09 20:20:40 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_mlx(t_fractal *fract)
{
	free(fract->mlx);
	print_error();
}

void	destroy_window(t_fractal *fract)
{
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	print_error();
}

void	destroy_image(t_fractal *fract)
{
	mlx_destroy_window(fract->mlx, fract->w);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	print_error();
}

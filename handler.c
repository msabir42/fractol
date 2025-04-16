/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:43:55 by msabir            #+#    #+#             */
/*   Updated: 2025/04/12 14:24:33 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mandelbrot(void)
{
	t_fractal	*fract;

	fract = malloc(sizeof(t_fractal));
	if (!fract)
		return (ft_putstr("Memory allocation failed\n"), 1);
	fract->c.real = 0;
	fract->c.imaginary = 0;
	init_mandelbrot(fract);
	free(fract);
	return (0);
}

int	handle_julia(int argc, char **argv)
{
	t_julia	julia;

	if (argc != 4)
	{
		ft_putstr("Julia fractal requires c_real and c_imag parameters.\n");
		ft_putstr("Usage: ./fractol Julia [c_real] [c_imag]\n");
		ft_putstr("Usage: ./fractol Julia -0.75 0.11 Try it\n");
		return (1);
	}
	if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
	{
		ft_putstr("Invalid input: Parameters must be valid float numbers.\n");
		return (1);
	}
	if (!check_bounds(ft_atof(argv[2]), ft_atof(argv[3])))
		return (1);
	init_julia(&julia, ft_atof(argv[2]), ft_atof(argv[3]));
	return (0);
}

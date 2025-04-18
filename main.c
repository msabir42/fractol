/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:45:47 by msabir            #+#    #+#             */
/*   Updated: 2025/04/11 10:27:03 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Usage: ./fractol Mandelbrot\n");
		ft_putstr("       ./fractol Julia [c_real] [c_imag]\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (handle_mandelbrot());
	else if (ft_strcmp(argv[1], "Julia") == 0)
		return (handle_julia(argc, argv));
	ft_putstr("Invalid fractal type. Choose Mandelbrot or Julia.\n");
	return (1);
}

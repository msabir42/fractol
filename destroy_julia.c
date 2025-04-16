/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:08:31 by msabir            #+#    #+#             */
/*   Updated: 2025/04/10 12:09:01 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_mlx_julia(t_julia *julia)
{
	free(julia->mlx);
	print_error();
}

void	destroy_window_julia(t_julia *julia)
{
	mlx_destroy_display(julia->mlx);
	free(julia->mlx);
	print_error();
}

void	destroy_image_julia(t_julia *julia)
{
	mlx_destroy_window(julia->mlx, julia->w);
	mlx_destroy_display(julia->mlx);
	free(julia->mlx);
	print_error();
}

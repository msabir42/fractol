/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:03:26 by msabir            #+#    #+#             */
/*   Updated: 2025/04/09 20:05:03 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_key_julia(int key, t_julia *julia)
{
	if (key == KEYSUM)
	{
		cleanup_julia(julia);
		exit(0);
	}
	return (0);
}

void	cleanup_julia(t_julia *julia)
{
	if (julia->data.img)
		mlx_destroy_image(julia->mlx, julia->data.img);
	if (julia->w)
		mlx_destroy_window(julia->mlx, julia->w);
	if (julia->mlx)
	{
		mlx_destroy_display(julia->mlx);
		free(julia->mlx);
	}
}

int	close_julia(t_julia *julia)
{
	cleanup_julia(julia);
	exit(0);
	return (0);
}

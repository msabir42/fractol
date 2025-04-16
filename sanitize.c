/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:58:26 by msabir            #+#    #+#             */
/*   Updated: 2025/04/11 12:27:45 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	has_valid_sign(const char *str)
{
	if (str[0] == '-' || str[0] == '+')
		return (1);
	return (0);
}

int	is_valid_float(const char *str)
{
	int	i;
	int	dot_count;
	int	digit_count;

	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (!str || !str[0])
		return (0);
	if (has_valid_sign(str))
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot_count++)
				return (0);
		}
		else if (ft_isdigit(str[i]))
			digit_count++;
		else
			return (0);
		i++;
	}
	return (digit_count > 0);
}

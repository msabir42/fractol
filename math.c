/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabir <msabir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:41:08 by msabir            #+#    #+#             */
/*   Updated: 2025/04/12 14:35:43 by msabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	char	*c;
	int		len;
	int		sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
	}
	c = (char *)str;
	res = (double)ft_atoi(c);
	while (*c && *c != '.')
		c++;
	if (*c == '.')
		c++;
	res2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		res2 /= 10;
	if (res >= 0)
		return ((res + res2) * sign);
	else
		return ((res + -res2) * sign);
}

t_complex	init_complex(double real, double imaginary)
{
	t_complex	new;

	new.real = real;
	new.imaginary = imaginary;
	return (new);
}

int	check_bounds(double input1, double input2)
{
	if (input1 < -2.0 || input1 > 2.0 || input2 < -2.0 || input2 > 2.0)
	{
		ft_putstr("Invalid input: Parameters must be inside the bounds\n");
		ft_putstr("MIN = -2.0 | MAX = 2.0\n");
		ft_putstr("Usage: ./fractol Julia -0.75 0.11 Try it \n");
		return (0);
	}
	return (1);
}

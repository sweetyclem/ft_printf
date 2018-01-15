/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:25:32 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/15 13:28:15 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	print_width(t_format format, int char_written)
{
	int	spaces_written;
	int	i;
	int	width;

	spaces_written = 0;
	width = format.min_width;
	i = 0;
	if (width > 0 && width > char_written && !format.zero && !format.minus)
	{
		spaces_written = width - char_written;
		i = spaces_written;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	return (spaces_written);
}

int	print_zero_padding(t_format format, int char_written)
{
	int	zeros_written;
	int	i;

	zeros_written = 0;
	i = 0;
	if (format.zero == 1 && (format.min_width > char_written))
	{
		zeros_written = format.min_width - char_written;
		i = zeros_written;
		while (i > 0)
		{
			ft_putchar('0');
			i--;
		}
	}
	return (zeros_written);
}

int	print_width_minus(t_format format, int char_written)
{
	int	spaces_written;
	int	i;
	int	width;

	spaces_written = 0;
	width = format.min_width;
	i = 0;
	if (width > 0 && width > char_written && !format.zero && format.minus)
	{
		spaces_written = width - char_written;
		i = spaces_written;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	return (spaces_written);
}

int	print_precision(t_format format, int nb)
{
	int	zeros_written;
	int	nb_len;
	int	i;

	zeros_written = 0;
	nb_len = ft_longlong_len(nb);
	i = 0;
	if (format.precision > nb_len)
	{
		zeros_written = format.precision - nb_len;
		if (nb < 0)
			zeros_written += 1;
		i = zeros_written;
		while (i > 0)
		{
			ft_putchar('0');
			i--;
		}
	}
	return (zeros_written);
}

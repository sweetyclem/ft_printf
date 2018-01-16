/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 08:25:32 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/16 14:21:04 by cpirlot          ###   ########.fr       */
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

int	print_precision(t_format format, int nb, int nb_len)
{
	int	zeros_written;
	int	i;

	zeros_written = 0;
	i = 0;
	if (nb < 0)
		nb_len -= 1;
	if (format.precision != -1 && format.precision > nb_len)
	{
		i = (format.precision - nb_len);
		while (i > 0)
		{
			ft_putchar('0');
			zeros_written++;
			i--;
		}
	}
	return (zeros_written);
}

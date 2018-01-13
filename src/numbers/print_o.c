/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:22:28 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/10 14:55:50 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	print_o_longlong(int char_written, t_format format, long long nb)
{
	char_written += ft_len_base(nb, 8);
	char_written += print_pound(format, nb);
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	ft_put_longlong_base(nb, 8);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

int	print_u_o_longlong(int char_written, t_format format, unsigned long long nb)
{
	char_written += ft_u_len_base(nb, 8);
	char_written += print_pound(format, nb);
	char_written += print_width(format, char_written);
	char_written += print_zero_padding(format, char_written);
	ft_put_u_longlong_base(nb, 8);
	char_written += print_width_minus(format, char_written);
	return (char_written);
}

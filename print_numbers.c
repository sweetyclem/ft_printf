/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 07:00:40 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/03 08:26:47 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int print_int(va_list *va)
{
    int char_written;
    long long int nb;

    char_written = 0;
    nb = (long long int)va_arg(*va, int);
	char_written = ft_longlong_len(nb);
	ft_putnbr(nb);
    return(char_written);
}

int print_int_base(va_list *va, char c)
{
    int char_written;

    char_written = 0;
	if (c == 'o' || c == 'O')
		char_written = print_o_int(va);
	else if (c == 'u' || c == 'U')
		char_written = print_u_int(va);
	else if (c == 'x')
	{

	}
	else if (c == 'X')
	{

	}
    return(char_written);
}

int print_u_int(va_list *va)
{
    int char_written;
    unsigned long long int nb;

    char_written = 0;
    nb = (unsigned long long int)va_arg(*va, long long int);
	char_written = ft_u_int_len(nb);
	ft_putnbr(nb);
    return(char_written);
}

int print_o_int(va_list *va)
{
    int char_written;
    unsigned long long int nb;

    char_written = 0;
    nb = (unsigned long long int)va_arg(*va, long long int);
	char_written = ft_uint_len_base(nb, 8);
	ft_put_longlong_base(nb, 8);
    return(char_written);
}

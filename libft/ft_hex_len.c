/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:40:29 by cpirlot           #+#    #+#             */
/*   Updated: 2018/01/10 09:43:45 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_hex_len(unsigned long long int nb)
{
	int char_written;

	char_written = 0;
	if (nb > UINT_MAX)
		char_written = 1;
	else if (nb < 16)
		char_written = 1;
	else
		char_written = ft_uint_len_base(nb, 16);
	return (char_written);
}
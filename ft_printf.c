/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:19:13 by cpirlot           #+#    #+#             */
/*   Updated: 2017/12/20 15:49:50 by cpirlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	parse_format(va_list *va, const char *format)
{
	size_t	char_written;
	int		i;
	char	*str;

	char_written = 0;
	i = 0;
	str = (char *)format;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_putstr(ft_strsub(str, 0, (i + 1)));
			char_written += parse_args(va, &str);
			
		}
		else
		{
			char_written++;
			i++;
		}
	}
	return (char_written);
}

int		ft_printf(const char *format, ...)
{
	size_t	char_written;
	va_list va;

	char_written = 0;
	if (format)
	{
		va_start(va, format);
		char_written = parse_format(&va, format);
		va_end(va);
	}
	return (char_written);
}
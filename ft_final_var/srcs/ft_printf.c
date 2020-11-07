/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:25 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 17:20:55 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	find_err(char *str)
{
	while (*str && (*str == ' ' || *str == 'h'))
		str++;
	if (!*str)
		return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_flag	flag;

	va_start(flag.lst, format);
	flag.len = 0;
	flag.format = (char *)format;
	new_buffer(&flag, BUFF_SIZE);
	while (*flag.format)
	{
		if (*flag.format == '%')
		{
			flag.format++;
			if (!*flag.format || find_err(flag.format))
				break ;
			flag_init(&flag);
			if (!ft_parse(&flag))
				break ;
		}
		else
			buffer(&flag, flag.format, 1);
		flag.format++;
	}
	va_end(flag.lst);
	write(1, flag.buff, flag.len);
	free(flag.buff);
	return (flag.len);
}

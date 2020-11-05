/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:25 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:12:28 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	put_err(char *s)
{
	while (*s && (*s == ' ' || *s == 'h'))
		s++;
	if (!*s)
		return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_print	p;

	va_start(p.lst, format);
	p.l = 0;
	p.format = (char *)format;
	init_buffer(&p, BUFF_SIZE);
	while (*p.format)
	{
		if (*p.format == '%')
		{
			p.format++;
			if (!*p.format || !put_err(p.format))
				break ;
			p_init(&p);
			if (!ft_parse(&p))
				break ;
		}
		else
			buffer(&p, p.format, 1);
		p.format++;
	}
	va_end(p.lst);
	write(1, p.buff, p.l);
	free(p.buff);
	return (p.l);
}

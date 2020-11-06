/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:38 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 20:00:29 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Parse flags "-+#0 "
*/

int		parse_flags(t_flag *f)
{
	int	i;

	i = 0;
	while (is_flag(f->format[i]))
		i++;
	if (ft_strchr(f->format, '0', 0, i))
		f->zero = 1;
	if (ft_strchr(f->format, '+', 0, i))
		f->plus = 1;
	if (ft_strchr(f->format, '-', 0, i))
		f->minus = -1;
	if (ft_strchr(f->format, '#', 0, i))
		f->hash = 1;
	if (ft_strchr(f->format, ' ', 0, i))
		f->space = 1;
	if (ft_strchr(f->format, '0', 0, i) && ft_strchr(f->format, '-', 0, i))
		f->zero = 0;
	if (ft_strchr(f->format, ' ', 0, i) && ft_strchr(f->format, '+', 0, i))
		f->space = 0;
	while (is_flag(*f->format))
		f->format++;
	return (i);
}

/*
** Parse width "<num>*" and precision flags ".*"
*/

int		parse_width(t_flag *flag)
{
	if (is_digit(*flag->format))
	{
		flag->width = ft_atoi(flag->format);
		while (is_digit(*flag->format))
			flag->format++;
		if (*flag->format == '*')
			flag->format++;
	}
	else if (*flag->format == '*')
	{
		flag->width = -1;
		flag->format++;
		if (is_digit(*flag->format))
		{
			flag->width = (int)va_arg(flag->lst, int);
			flag->width = ft_atoi(flag->format);
		}
		while (is_digit(*flag->format))
			flag->format++;
	}
	return (1);
}

int		parse_precision(t_flag *flag)
{
	if (*flag->format == '.')
	{
		flag->dot = 1;
		flag->format++;
		if (is_digit(*flag->format))
		{
			flag->prec = ft_atoi(flag->format);
			while (is_digit(*flag->format))
				flag->format++;
		}
		else if (*flag->format == '*')
		{
			flag->format++;
			flag->prec = -1;
		}
		else
			flag->prec = 0;
	}
	return (1);
}

/*
** Parse size "lhL"
*/

void	parse_size(t_flag *f)
{
	if (is_size(*f->format))
	{
		if (*f->format == 'h')
			f->size = (*(f->format + 1) == 'h') ? F_SCHAR : F_SHORT;
		else if (*f->format == 'l')
			f->size = (*(f->format + 1) == 'l') ? F_LLONG : F_LONG;
		else if (*f->format == 'L')
			f->size = F_LLONG;
		else if (*f->format == 'j')
			f->size = F_INTMAX;
		else if (*f->format == 'z')
			f->size = F_SIZET;
		f->format++;
		if (*f->format == 'h' || *f->format == 'l' || *f->format == 'L')
			f->format++;
	}
}

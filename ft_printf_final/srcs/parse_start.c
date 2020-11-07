/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:22 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 21:19:17 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Parse specifier "dDioOuUxXfFcCsSp%"
*/

static int			is_allowed_spec(char *format)
{
	if (format == NULL || format[0] == 0)
		return (0);
	if (ft_str_search("diDoOuUxXfFsScCp%", format[0]) == 0)
		return (0);
	return (1);
}

int					parse_type(t_flag *flag)
{
	static t_func	f[256];
	int				n;

	f['d'] = transform_int;
	f['i'] = transform_int;
	f['D'] = transform_int;
	f['o'] = transform_oct;
	f['O'] = transform_oct;
	f['u'] = transform_uint;
	f['U'] = transform_uint;
	f['x'] = transform_hex;
	f['X'] = transform_hex;
	f['f'] = transform_double;
	f['F'] = transform_double;
	f['s'] = transform_str;
	f['S'] = transform_str;
	f['c'] = transform_char;
	f['C'] = transform_char;
	f['p'] = transform_pointer;
	f['%'] = transform_perc;
	n = is_allowed_spec(flag->format) ? f[(int)(*flag->format)](flag) : 0;
	return (n);
}

static void			width_prec_correct(t_flag *flag)
{
	if (flag->width == -1)
	{
		flag->width = (int)va_arg(flag->lst, int);
		if (flag->width < 0)
			flag->minus = -1;
		else
			flag->minus = flag->minus;
		if (flag->width < 0)
			flag->width = flag->width * -1;
		else
			flag->width = flag->width;
	}
	if (flag->prec < 0)
		flag->prec = (int)va_arg(flag->lst, int);
}

int					ft_parse(t_flag *flag)
{
	int				i;

	i = 0;
	while (*flag->format && is_valid(*flag->format))
	{
		parse_flags(flag);
		parse_width(flag);
		parse_precision(flag);
		parse_size(flag);
	}
	if (*flag->format && !is_type(*flag->format))
	{
		buffer(flag, flag->format, 1);
		return (1);
	}
	if (!(*flag->format))
		return (0);
	width_prec_correct(flag);
	if (*flag->format > 67 && *flag->format < 89)
		flag->cap = F_UPCASE;
	i = parse_type(flag);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:02 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:43:01 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			put_char(t_flag *flag, int c)
{
	char		*s;
	int			i;

	i = 1;
	i = (flag->width > i) ? flag->width : i;
	flag->width = (flag->width > i) ? flag->width : i;
	s = (char *)malloc(sizeof(char) * i + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	i = (flag->minus < 0 && c != 0) ? 0 : (flag->width - 1);
	s[i] = (char)c;
	i = 0;
	if (flag->zero)
	{
		while (i < flag->width - 1)
			s[i++] = '0';
	}
	if (flag->minus < 0 && c == 0)
	{
		buffer(flag, "\0", 1);
		buffer(flag, s, (flag->width - 1));
	}
	else
		buffer(flag, s, flag->width);
	free(s);
}

static char		*fills(t_flag *flag, char *str, int i, int l)
{
	char		*s;
	int			j;

	j = 0;
	s = (char *)malloc(sizeof(char) * i + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	if (flag->minus >= 0)
	{
		while (j < i - l)
			s[j++] = (flag->zero) ? '0' : ' ';
	}
	i = 0;
	while (str[i] && i < l)
		s[j++] = str[i++];
	if (flag->minus < 0)
	{
		while (j < flag->width)
			s[j++] = ' ';
	}
	return (s);
}

static void		put_str(t_flag *flag, char *str)
{
	char		*s;
	int			i;
	int			l;

	i = 0;
	while (str[i])
		i++;
	if (flag->prec >= 0)
		i = (flag->dot && i > flag->prec) ? flag->prec : i;
	l = i;
	if (flag->width > i)
		i = flag->width;
	if (flag->width < i)
		flag->width = i;
	s = fills(flag, str, i, l);
	buffer(flag, s, flag->width);
	free(s);
}

int				transform_char(t_flag *flag)
{
	unsigned	c;

	if (flag->size && (flag->size == F_LLONG || flag->size == F_SHORT
	|| flag->size == F_SCHAR))
		flag->size = 0;
	if (flag->plus)
		flag->plus = 0;
	if (flag->hash)
		flag->hash = 0;
	c = va_arg(flag->lst, unsigned);
	if (!c)
		put_char(flag, 0);
	else
		put_char(flag, c);
	return (1);
}

int				transform_str(t_flag *flag)
{
	unsigned	*str;

	if (flag->size && (flag->size == F_LLONG || flag->size == F_SHORT
	|| flag->size == F_SCHAR))
		flag->size = 0;
	if (flag->plus)
		flag->plus = 0;
	if (flag->hash)
		flag->hash = 0;
	str = va_arg(flag->lst, unsigned*);
	if (!str)
		put_str(flag, "(null)");
	else
		put_str(flag, (char *)str);
	return (1);
}

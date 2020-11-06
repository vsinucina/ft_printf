/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:18 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:39:18 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			clc_l(t_flag *flag, int *i, long double n, intmax_t d)
{
	int				len;

	len = 1;
	while ((d /= 10) >= 1)
		len++;
	*i = (flag->dot) ? flag->prec : 6;
	flag->prec = (flag->dot) ? flag->prec : 6;
	if (n < 0)
		flag->plus = -1;
	*i = (flag->plus || flag->space) ? *i + 1 : *i;
	*i = (flag->prec == 0 && flag->dot && flag->hash) ? *i + 1 : *i;
	*i = (flag->prec) ? *i + 1 : *i;
	*i = (flag->width > len + *i) ? flag->width : len + *i;
	flag->width = *i;
	return (len);
}

static void			cpy(t_flag *flag, char *s, unsigned long t)
{
	int				i;
	int				j;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	j = i;
	i = i + flag->prec;
	while (i > j)
	{
		s[i--] = t % (long)10 + '0';
		t /= (long)10;
	}
}

static int			m_str(t_flag *flag, char *s, intmax_t d, int l)
{
	int				i;
	int				j;

	i = fill_width(flag, s);
	if (flag->minus >= 0)
	{
		j = flag->prec;
		while (j-- > 0)
			s[i--] = '0';
	}
	else
	{
		j = l;
		while (j-- > 0)
			i++;
	}
	(flag->prec || flag->hash) ? (s[i--] = '.') : 0;
	i = (!flag->prec && !flag->hash && flag->minus < 0) ? i - 1 : i;
	(d == 0) ? (s[i--] = '0') : 0;
	while (d)
	{
		s[i--] = d % 10 + '0';
		d /= 10;
	}
	return (i);
}

void				ft_ldtoa(t_flag *flag, long double n)
{
	int				i;
	int				l;
	intmax_t		d;
	char			*s;
	unsigned long	t;

	i = 0;
	d = calc_d(flag, n, &t);
	l = clc_l(flag, &i, n, d);
	s = (char *)malloc(sizeof(char) * i + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	i = m_str(flag, s, d, l);
	i = (flag->minus < 0 && (flag->prec || flag->hash)) ? (i + 1) : i;
	flag_con(flag, s, i, l);
	cpy(flag, s, t);
	buffer(flag, s, flag->width);
}

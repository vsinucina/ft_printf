/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:12 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 21:19:42 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			flag_con(t_flag *flag, char *s, int i, int len)
{
	if (flag->minus < 0)
	{
		i = i + len + 1;
		while (i < flag->width)
			s[i++] = ' ';
	}
	else
	{
		if (flag->plus)
		{
			while (s[i] == '0')
				i--;
			s[i] = (flag->plus > 0) ? '+' : '-';
		}
		if (flag->zero)
		{
			while (i > 0)
				s[i--] = '0';
			if (flag->plus)
				s[0] = (flag->plus > 0) ? '+' : '-';
		}
	}
}

void			make_s(t_flag *flag, char *s, int l, long long nbr)
{
	int			i;
	int			j;

	i = fill_width(flag, s);
	j = flag->prec;
	while (j > 0)
	{
		s[i] = '0';
		i = (flag->minus >= 0) ? i - 1 : i + 1;
		j--;
	}
	i = (flag->minus >= 0) ? i + flag->prec : i - 1;
	while (nbr)
	{
		s[i--] = nbr % (unsigned long)10 + '0';
		nbr /= (unsigned long)10;
	}
	flag_con(flag, s, i, l);
}

static void		find_long(t_flag *flag, int *i, long long nbr)
{
	*i = (flag->prec > *i) ? flag->prec : *i;
	if (flag->zero && flag->dot && flag->prec >= 0)
		flag->zero = 0;
	if (flag->prec < 0)
		flag->prec = 0;
	flag->prec = (flag->prec <= *i) ? *i : flag->prec;
	flag->plus = (nbr < 0) ? -1 : flag->plus;
	*i = (flag->plus || flag->space) ? *i + 1 : *i;
	*i = (flag->width > *i) ? flag->width : *i;
	flag->width = *i;
}

static void		max_fix(char *str, int num, int j)
{
	if (num == -2)
	{
		j--;
		while (str[j] != '7')
			j--;
		str[j] = '8';
	}
}

void			ft_itoa(t_flag *flag, long long nbr)
{
	int			i;
	int			l;
	long long	n;
	char		*s;

	i = (flag->dot && flag->prec == 0 && nbr == 0) ? 0 : 1;
	n = (nbr < 0 && nbr != LONG_MIN) ? -1 * nbr : nbr;
	n = (nbr == LONG_MIN) ? LONG_MAX : n;
	while ((n /= 10) >= 1)
		i++;
	l = i;
	find_long(flag, &i, nbr);
	s = (char *)malloc(i * sizeof(char) + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	n = (nbr < 0) ? -1 : 1;
	n = (nbr == LONG_MIN) ? -2 : n;
	nbr = (nbr == LONG_MIN) ? LONG_MAX : nbr * n;
	make_s(flag, s, l, nbr);
	max_fix(s, n, i);
	buffer(flag, s, flag->width);
	free(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:09 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 21:20:22 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						fill_width(t_flag *flag, char *str)
{
	int					i;

	i = 0;
	if (flag->minus >= 0)
	{
		if (flag->space)
			str[i++] = ' ';
		while (i < flag->width)
			str[i++] = (flag->zero) ? '0' : ' ';
		i--;
	}
	else
	{
		if (flag->plus)
			str[i++] = (flag->plus > 0) ? '+' : '-';
		else if (flag->space)
			str[i++] = ' ';
	}
	return (i);
}

static int				mk(t_flag *f, char *s, int b, unsigned long long n)
{
	int					j;
	int					i;

	i = fill_width(f, s);
	j = f->prec;
	while (j > 0)
	{
		s[i] = '0';
		if (((b == 16 && f->hash && n != 0) || (b == 16 && f->hash && f->pnt))
		&& ((f->minus < 0 && j == f->prec - 1) || (f->minus >= 0 && j == 2)))
			s[i] = 'x' - f->cap;
		i = (f->minus >= 0) ? i - 1 : i + 1;
		j--;
	}
	i = (f->minus >= 0) ? i + f->prec : i - 1;
	while (n)
	{
		s[i--] = ((n % (unsigned long)b) < 10) ?
		n % (unsigned long)b + '0'
		: n % (unsigned long)b + 'a' - 10 - f->cap;
		n /= (unsigned long)b;
	}
	if (i >= 0)
		s[i] = (b == 8 && f->hash) ? '0' : s[i];
	return (i);
}

static void				set_p(t_flag *f, int *i, unsigned long long nb, int b)
{
	if (f->zero && f->dot && f->prec >= 0)
		f->zero = 0;
	if (f->prec < 0)
		f->prec = 0;
	*i = (f->prec > *i) ? f->prec : *i;
	f->prec = (f->prec <= *i) ? *i : f->prec;
	*i = (b == 16 && f->hash && (nb != 0 || f->pnt)) ? *i + 2 : *i;
	f->prec = (b == 16 && f->hash && (nb != 0 || f->pnt)) ?
			f->prec + 2 : f->prec;
	*i = (f->width > *i) ? f->width : *i;
	f->width = *i;
}

void					ft_itoa_base(t_flag *f, unsigned long long nb, int b)
{
	int					i;
	int					len;
	unsigned long long	n;
	char				*s;

	len = (f->dot && f->prec == 0 && nb == 0) ? 0 : 1;
	n = nb;
	while ((n /= b) >= 1)
		len++;
	i = (b == 8 && f->hash && (nb != 0 || f->dot)) ? len + 1 : len;
	set_p(f, &i, nb, b);
	s = (char *)malloc(i * sizeof(char) + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	i = mk(f, s, b, nb);
	flag_con(f, s, i, len);
	s[1] = (f->zero && b == 16 && f->hash && nb != 0) ? ('x' - f->cap) : s[1];
	buffer(f, s, f->width);
	free(s);
}

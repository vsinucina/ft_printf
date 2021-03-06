/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:10:57 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 21:19:06 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			fix_pre(t_flag *f, unsigned long *t, long double n, int l)
{
	long double		e;
	intmax_t		d;

	d = (n < 0) ? -1 * (intmax_t)n : (intmax_t)n;
	e = (n - (long)d) * ft_power(10, l);
	*t = (e > 0.5 && e < 1) ? 1 : *t;
	if (f->prec < 16)
		*t = (*t % 10 >= 5) ? (*t + (10 - *t % 10)) : *t;
	if (f->prec >= 16 && f->prec < 20)
	{
		*t = ((unsigned long)(e * 10) % 10 > 5) ? *t + 1 : *t;
		*t = (*t % 10 > 5) ? (*t + (10 - *t % 10)) : *t;
	}
	if (f->prec == 20)
		*t = (e - (long double)*t > 0.4) ? *t + 1 : *t;
}

intmax_t			calc_d(t_flag *flag, long double n, unsigned long *t)
{
	int				l;
	int				i;
	intmax_t		d;
	unsigned long	temp;

	i = (flag->prec == 20) ? 1 : 0;
	d = (n < 0) ? -1 * (intmax_t)n : (intmax_t)n;
	n = (n < 0) ? -n : n;
	flag->prec = (flag->dot) ? flag->prec : 6;
	l = (flag->prec >= 20) ? 20 : flag->prec + 1;
	*t = (unsigned long)((n - (long)d) * ft_power(10, l));
	fix_pre(flag, t, n, l);
	temp = *t;
	while (i <= flag->prec)
	{
		temp /= 10;
		i++;
	}
	d = (temp == 1) ? d + 1 : d;
	*t = (temp == 1) ? 0 : *t;
	*t = (flag->prec == 20) ? *t : (*t / 10);
	return (d);
}

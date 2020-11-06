/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:27 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:40:52 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					ft_utoa(t_flag *flag, unsigned long long nbr)
{
	int					i;
	int					l;
	unsigned long long	n;
	char				*s;

	i = (flag->dot && flag->prec == 0 && nbr == 0) ? 0 : 1;
	n = nbr;
	while ((n /= 10) >= 1)
		i++;
	l = i;
	i = (flag->prec > i) ? flag->prec : i;
	if (flag->zero && flag->dot && flag->prec >= 0)
		flag->zero = 0;
	if (flag->prec < 0)
		flag->prec = 0;
	flag->prec = (flag->prec <= i) ? i : flag->prec;
	i = (flag->width > i) ? flag->width : i;
	flag->width = i;
	s = (char *)malloc(i * sizeof(char) + 1);
	ft_memset((void *)s, ' ', i);
	s[i] = '\0';
	make_s(flag, s, l, nbr);
	buffer(flag, s, flag->width);
	free(s);
}

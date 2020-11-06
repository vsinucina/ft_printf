/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_transform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:35 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:12:31 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			trf_pointer(t_print *p)
{
	void	*pnt;

	pnt = va_arg(p->lst, void *);
	p->pnt = 1;
	p->hash = 1;
	if (pnt == 0)
	{
		if (p->dot)
			p->width = (p->width) ? p->width : 2;
		else
			p->width = (p->width) ? p->width : 3;
	}
	if (p->flag)
		p->flag = 0;
	if (p->sign)
		p->sign = 0;
	ft_itoa_b(p, (unsigned long long)pnt, 16);
	return (1);
}

int			trf_perc(t_print *p)
{
	put_char_pf(p, (int)'%');
	return (1);
}

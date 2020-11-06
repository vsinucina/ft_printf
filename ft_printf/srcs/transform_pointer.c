/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:35 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:43:41 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			transform_pointer(t_flag *flag)
{
	void	*pnt;

	pnt = va_arg(flag->lst, void *);
	flag->pnt = 1;
	flag->hash = 1;
	if (pnt == 0)
	{
		if (flag->dot)
			flag->width = (flag->width) ? flag->width : 2;
		else
			flag->width = (flag->width) ? flag->width : 3;
	}
	if (flag->size)
		flag->size = 0;
	if (flag->plus)
		flag->plus = 0;
	ft_itoa_base(flag, (unsigned long long)pnt, 16);
	return (1);
}

int			transform_perc(t_flag *flag)
{
	put_char(flag, (int)'%');
	return (1);
}

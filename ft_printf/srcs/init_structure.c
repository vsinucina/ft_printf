/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:22 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:41:09 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				flag_init(t_flag *flag)
{
	flag->minus = 0;
	flag->width = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->space = 0;
	flag->prec = 0;
	flag->dot = 0;
	flag->size = 0;
	flag->cap = 0;
	flag->pnt = 0;
}

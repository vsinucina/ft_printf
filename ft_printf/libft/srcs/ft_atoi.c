/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:05:12 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:07:21 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_atoi(const char *str)
{
	__int128_t	f;
	int			sign;

	if (!str)
		return (0);
	f = 0;
	sign = 1;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while (is_digit(*str) && f < ATOI_MAX)
		f = (f << 3) + (f << 1) + *str++ + (~0x30 + 1);
	if (f >= ATOI_MAX)
		f = sign < 0 ? 0 : -1;
	return ((int)f * sign);
}

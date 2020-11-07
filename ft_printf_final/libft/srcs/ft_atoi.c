/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:05:12 by akelli            #+#    #+#             */
/*   Updated: 2020/11/07 06:17:16 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_atoi(const char *str)
{
	__int128_t			f;
	int					sign;
	unsigned long long	atoi_max;

	atoi_max = 1;
	atoi_max <<= ((sizeof(size_t) * 8) - 1);
	if (!str)
		return (0);
	f = 0;
	sign = 1;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	while (is_digit(*str) && f < atoi_max)
		f = (f << 3) + (f << 1) + *str++ + (~0x30 + 1);
	if (f >= atoi_max)
		f = sign < 0 ? 0 : -1;
	return ((int)f * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:06:00 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:08:36 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_is_negative(char *s)
{
	unsigned char	zero;

	if (!s)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		s++;
	else
		return (0);
	zero = 0;
	while (*s)
	{
		if (!is_digit(*s))
			return (0);
		zero |= (unsigned char)*s - 48;
		s++;
	}
	return (zero != 0);
}

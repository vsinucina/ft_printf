/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:06:25 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:08:41 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;

	if (n == 0)
		return (str);
	s = (unsigned char *)str;
	while (n)
	{
		*s = (unsigned char)c;
		s++;
		n--;
	}
	return (str);
}

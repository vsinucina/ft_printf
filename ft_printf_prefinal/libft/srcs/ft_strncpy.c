/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:07:04 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:09:01 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	int				j;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	while (i < n)
	{
		if (j == 1)
			dest[i] = '\0';
		else if (src[i] == '\0')
		{
			j = 1;
			dest[i] = '\0';
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}

char				*ft_str_n_copy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

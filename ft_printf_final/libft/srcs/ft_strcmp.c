/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:06:59 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:08:55 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	if (!n)
		return (0);
	i = 0;
	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	while (cmp1[i] == cmp2[i] && cmp1[i] && cmp2[i] && i + 1 < n)
		i++;
	return (cmp1[i] - cmp2[i]);
}

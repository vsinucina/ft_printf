/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:07:02 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:08:59 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (!(dest = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strndup(const char *src, size_t size)
{
	size_t	i;
	char	*dest;

	if (!src)
		return (NULL);
	if (!(dest = (char *)malloc(size * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
		dest[i++] = '\0';
	dest[i] = '\0';
	return (dest);
}

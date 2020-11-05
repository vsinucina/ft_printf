/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:06:28 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:09:37 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_power(long double n, int p)
{
	if (p < 0)
		return (1);
	if (p)
		return (n * ft_power(n, p - 1));
	return (1);
}

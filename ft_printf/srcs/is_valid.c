/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:29 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:12:30 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		is_converse(char c)
{
	char	*s;

	s = "%dDioOuUxXeEfFcCsSp%";
	while (*s)
	{
		if (c == *s)
			return (c);
		s++;
	}
	return (0);
}

char		is_modifier(char c)
{
	char	*s;

	s = "zjhlL";
	while (*s)
	{
		if (c == *s)
			return (c);
		s++;
	}
	return (0);
}

char		is_flag(char c)
{
	char	*s;

	s = "#0-+ ";
	while (*s)
	{
		if (c == *s)
			return (c);
		s++;
	}
	return (0);
}

char		is_precision(char c)
{
	char	*s;

	s = "*.";
	while (*s)
	{
		if (c == *s)
			return (c);
		s++;
	}
	return (0);
}

int			is_valid(char c)
{
	if (is_modifier(c) || is_flag(c) || is_digit(c)
	|| is_precision(c))
		return (1);
	return (0);
}

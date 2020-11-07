/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_increase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:04 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:23:27 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	plus_buff(t_flag *flag, int len)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (flag->len + len) + 1);
	if (!new)
		return (0);
	ft_strncpy(new, flag->buff, flag->len);
	free(flag->buff);
	flag->buff = new;
	return (1);
}

void		buffer(t_flag *flag, char *str, int len)
{
	if (flag->len + len > BUFF_SIZE)
		plus_buff(flag, len);
	ft_strncpy((flag->buff + flag->len), str, (size_t)len);
	flag->len = flag->len + len;
}

int			new_buffer(t_flag *flag, int len)
{
	flag->buff = (char *)malloc(sizeof(char) * len);
	if (!(flag->buff))
		return (0);
	return (1);
}

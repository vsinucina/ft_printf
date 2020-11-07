/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:11:32 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 19:43:22 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						transform_int(t_flag *flag)
{
	long long			i;

	if (flag->hash)
		flag->hash = 0;
	if (flag->size && flag->size == F_LONG)
		i = (long long)va_arg(flag->lst, long);
	else if (flag->size && flag->size == F_LLONG)
		i = (long long)va_arg(flag->lst, long long);
	else if (flag->size && flag->size == F_SHORT)
		i = (long long)((short)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_SCHAR)
		i = (long long)((char)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_INTMAX)
		i = (long long)va_arg(flag->lst, intmax_t);
	else if (flag->size && flag->size == F_SIZET)
		i = (long long)va_arg(flag->lst, ssize_t);
	else
		i = (long long)va_arg(flag->lst, int);
	ft_itoa(flag, i);
	return (1);
}

int						transform_uint(t_flag *flag)
{
	unsigned long long	ui;

	if (flag->hash)
		flag->hash = 0;
	if (flag->plus)
		flag->plus = 0;
	if (flag->space)
		flag->space = 0;
	if ((flag->size && flag->size == F_LONG) || flag->cap)
		ui = (unsigned long long)va_arg(flag->lst, unsigned long);
	else if (flag->size && flag->size == F_LLONG)
		ui = (unsigned long long)va_arg(flag->lst, unsigned long long);
	else if (flag->size && flag->size == F_SHORT)
		ui = (unsigned long long)(va_arg(flag->lst, unsigned long long));
	else if (flag->size && flag->size == F_SCHAR)
		ui = (unsigned long long)((unsigned char)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_INTMAX)
		ui = (unsigned long long)va_arg(flag->lst, uintmax_t);
	else if (flag->size && flag->size == F_SIZET)
		ui = (unsigned long long)va_arg(flag->lst, ssize_t);
	else
		ui = (unsigned long long)va_arg(flag->lst, unsigned int);
	ft_utoa(flag, ui);
	return (1);
}

int						transform_oct(t_flag *flag)
{
	unsigned long long	ui;

	if (flag->plus)
		flag->plus = 0;
	if (flag->space)
		flag->space = 0;
	if (flag->size && flag->size == F_LONG)
		ui = (unsigned long)va_arg(flag->lst, unsigned long);
	else if (flag->size && flag->size == F_LLONG)
		ui = (unsigned long long)va_arg(flag->lst, unsigned long long);
	else if (flag->size && flag->size == F_SHORT)
		ui = (unsigned long)((unsigned short)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_SCHAR)
		ui = (unsigned long)((unsigned char)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_INTMAX)
		ui = (unsigned long long)va_arg(flag->lst, uintmax_t);
	else if (flag->size && flag->size == F_SIZET)
		ui = (unsigned long long)va_arg(flag->lst, ssize_t);
	else
		ui = (unsigned long)va_arg(flag->lst, unsigned int);
	ft_itoa_base(flag, ui, 8);
	return (1);
}

int						transform_hex(t_flag *flag)
{
	unsigned long long	ui;

	if (flag->plus)
		flag->plus = 0;
	if (flag->space)
		flag->space = 0;
	if (flag->size && flag->size == F_LONG)
		ui = (unsigned long)va_arg(flag->lst, unsigned long);
	else if (flag->size && flag->size == F_LLONG)
		ui = (unsigned long long)va_arg(flag->lst, unsigned long long);
	else if (flag->size && flag->size == F_SHORT)
		ui = (unsigned long)((unsigned short)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_SCHAR)
		ui = (unsigned long)((unsigned char)va_arg(flag->lst, int));
	else if (flag->size && flag->size == F_INTMAX)
		ui = (unsigned long long)va_arg(flag->lst, uintmax_t);
	else if (flag->size && flag->size == F_SIZET)
		ui = (unsigned long long)va_arg(flag->lst, ssize_t);
	else
		ui = (unsigned long)va_arg(flag->lst, unsigned int);
	ft_itoa_base(flag, ui, 16);
	return (1);
}

int						transform_double(t_flag *flag)
{
	long double			i;

	if (flag->size && flag->size == F_LLONG)
		i = (long double)va_arg(flag->lst, long double);
	else if (flag->size && flag->size == F_LONG)
		i = (long double)va_arg(flag->lst, double);
	else
		i = (long double)va_arg(flag->lst, double);
	ft_ldtoa(flag, i);
	return (1);
}

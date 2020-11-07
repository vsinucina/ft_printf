/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:40 by akelli            #+#    #+#             */
/*   Updated: 2020/11/06 21:18:22 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"

typedef	struct	s_flag
{
	int			len;
	char		*format;
	char		*buff;
	va_list		lst;
	int			minus;
	int			width;
	int			plus;
	int			zero;
	int			hash;
	int			space;
	int			prec;
	int			dot;
	int			size;
	int			cap;
	int			pnt;
}				t_flag;

typedef int		(*t_func)(t_flag*);

int				ft_printf(const char *format, ...);

/*
** Number conversion
*/

void			ft_itoa(t_flag *flag, long long nbr);
void			ft_utoa(t_flag *flag, unsigned long long nbr);
void			ft_itoa_base(t_flag *f, unsigned long long nb, int b);
void			ft_ldtoa(t_flag *flag, long double n);

/*
** Auxiliary functions
*/

void			flag_init(t_flag *flag);
int				fill_width(t_flag *flag, char *str);
void			flag_con(t_flag *flag, char *s, int i, int len);
void			make_s(t_flag *flag, char *s, int l, long long nbr);
void			put_char(t_flag *flag, int c);
intmax_t		calc_d(t_flag *flag, long double n, unsigned long *t);

/*
** Check input functions
*/

char			is_type(char c);
char			is_size(char c);
char			is_flag(char c);
char			is_precision(char c);
int				is_valid(char c);

/*
** Parse flags
*/
int				parse_flags(t_flag *flag);
int				parse_width(t_flag *flag);
int				parse_precision(t_flag *flag);
void			parse_size(t_flag *flag);
int				parse_spec(t_flag *flag);
int				ft_parse(t_flag *flag);

/*
** Transform arguments
*/
int				transform_int(t_flag *flag);
int				transform_uint(t_flag *flag);
int				transform_oct(t_flag *flag);
int				transform_hex(t_flag *flag);
int				transform_double(t_flag *flag);
int				transform_char(t_flag *flag);
int				transform_str(t_flag *flag);
int				transform_pointer(t_flag *flag);
int				transform_perc(t_flag *flag);

/*
** Save result in a string
*/

void			buffer(t_flag *flag, char *s, int i);
int				new_buffer(t_flag *flag, int len);

#endif

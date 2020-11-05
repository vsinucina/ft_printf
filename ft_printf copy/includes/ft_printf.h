/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:17:40 by akelli            #+#    #+#             */
/*   Updated: 2020/11/04 19:17:59 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"

typedef	struct	s_print
{
	int			l;
	char		*format;
	char		*buff;
	va_list		lst;
	int			just;
	int			width;
	int			sign;
	int			deli;
	int			hash;
	int			sp;
	int			prec;
	int			dot;
	int			flag;
	int			cap;
	int			pnt;
	char		col;
}				t_print;

typedef int		(*t_func)(t_print*);

int				ft_printf(const char *format, ...);

/*
** Number conversion
*/

void			ft_itoa_pf(t_print *p, long long nbr);
void			ft_utoa_pf(t_print *p, unsigned long long nbr);
void			ft_itoa_b(t_print *p, unsigned long long nb, int b);
void			ft_ldtoa_pf(t_print *p, long double n);

/*
** Auxiliary functions
*/

void			p_init(t_print *p);
int				fill_width(t_print *p, char *s);
void			est_sign(t_print *p, char *s, int i, int l);
void			make_s(t_print *p, char *s, int l, long long nbr);
void			put_char_pf(t_print *p, int c);
intmax_t		calc_d(t_print *p, long double n, unsigned long *t);

/*
** Check input functions
*/

char			is_converse(char c);
char			is_modifier(char c);
char			is_flag(char c);
char			is_precision(char c);
int				is_valid(char c);

/*
** Parse flags
*/
int				prs_flags(t_print *p);
int				prs_width(t_print *p);
int				prs_prec(t_print *p);
void			prs_lenspec(t_print *p);
int				prs_spec(t_print *p);
int				ft_parse(t_print *p);

/*
** Transform arguments
*/
int				trf_int(t_print *p);
int				trf_uint(t_print *p);
int				trf_oct(t_print *p);
int				trf_hex(t_print *p);
int				trf_double(t_print *p);
int				trf_char(t_print *p);
int				trf_str(t_print *p);
int				trf_pointer(t_print *p);
int				trf_perc(t_print *p);

/*
** Save result in a string
*/

void			buffer(t_print *p, char *s, int i);
int				init_buffer(t_print *p, int l);
void			ft_putcolor(t_print *p);

#endif

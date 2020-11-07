/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <akelli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:05:54 by akelli            #+#    #+#             */
/*   Updated: 2020/11/07 06:20:31 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>

# define BUFF_SIZE	100

# define F_INT			1
# define F_UPCASE		32
# define F_SHORT		3
# define F_SCHAR		4
# define F_LONG			5
# define F_LLONG		6
# define F_SIZET		7
# define F_INTMAX		8

typedef int				t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Libft functions
*/

char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(char *str, char c, int i, int j);
void			*ft_memset(void *str, int c, size_t n);
int				ft_atoi(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_str_n_copy(char *dst, const char *src, size_t len);
long double		ft_power(long double n, int p);
void			ft_bzero(void *str, size_t n);
void			*ft_memalloc(size_t size);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t size);
size_t			ft_strlen(const char *str);
void			ft_putnchar(int len, char c);
void			ft_putstr_free(char const *s);
char			*ft_str_search(const char *s, int c);

char			is_digit(char c);
int				is_num(char *s);
int				ft_isspace(int c);
int				ft_is_negative(char *s);

#endif

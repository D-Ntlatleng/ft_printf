/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dntlatle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:28:55 by dntlatle          #+#    #+#             */
/*   Updated: 2018/08/28 12:59:10 by dntlatle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <locale.h>
# include <limits.h>

typedef struct	s_flag{
	int						sp;
	int						minus;
	int						plus;
	int						zero;
	int						hash;
	int						h;
	int						hh;
	int						l;
	int						ll;
	int						j;
	int						z;
	int						width;
	int						pre;
	int						x;
	int						base;
	int						temp;
	int						sign;
	char					*str;
	wchar_t					*wstr;
	unsigned long long int	uvalue;
	long long int			value;
	int						ans;
}				t_flag;
char			*ft_strchr(const char *str, int c);
void			hex(t_flag *my);
void			octal(t_flag *my);
void			hex_check(t_flag *my, va_list flags, int base);
void			dec_check(t_flag *my, va_list flags);
void			octal_check(t_flag *my, va_list flags, int base);
void			str_check(t_flag *my, va_list flags, char c);
void			pointer(t_flag *my, unsigned long a);
void			char_check(t_flag *my, va_list flags, char c);
int				move(const char *fmt);
int				precision(const char *fmt, va_list flags, t_flag *my);
void			percent(t_flag *my);
int				width(const char *fmt, va_list flags, t_flag *my);
void			ft_putnbr(long long n, t_flag *my);
int				ft_length(const char *fmt, t_flag *my);
int				ft_flags(const char *fm, t_flag *my);
int				char_con(char c, t_flag *my, va_list flags);
void			decimal(t_flag *my);
void			charector(unsigned int code, t_flag *my);
void			pristr(t_flag *my);
void			ft_putchar(int c, t_flag *my);
void			ft_base(unsigned long long n, char *ch, size_t base, size_t j);
void			ft_putstr(const char *s, t_flag *my);
void			ft_putcstr(t_flag *my);
size_t			ft_wstrlen(const wchar_t *s);
size_t			ft_strlen(const char *s);
size_t			fsize(unsigned long long n, int base);
int				ft_printf(const char *fmt, ...);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
char			*ft_strrev(char *s);
void			ft_putwstr(t_flag *my);

#endif

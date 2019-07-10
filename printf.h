/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/09 20:07:43 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"

int	result;

typedef struct  s_pattern
{
	int         hash;
	int         minus;
	int         plus;
	int         space;
	int         zero;
	int         width;
	int         precision;
	int         h;
	int			hh;
	int         l;
	int			L;
	int         ll;
	int			help;
	char        type;
}				t_pattern;

typedef	struct				s_formlfb
{
    unsigned long int		mantisa : 64;
    unsigned				exponent : 15;
    unsigned				sign : 1;
}							t_formlfb;

typedef	union				u_formlf
{
    long double				f;
    t_formlfb				bytes;
}							t_form_lf;

void    print_u(t_pattern tmp, va_list factor);
void    print_s(t_pattern tmp, va_list factor);
void		print_c(t_pattern tmp, char c);
void	ft_print_f(t_pattern tmp, long double nbr);
long long        va_arg_help(va_list factor, t_pattern *tmp);
void    put_cast(t_pattern *tmp, const char *format, int *i);
int     ft_cast(char c); 
void    print_help (int pre, long long *digit);
int     ft_num(const char *format, int *i, va_list factor);
void new_pattern(t_pattern *tmp);
int	type(char c);
int	ft_flag(char c);
void  addflag(t_pattern *tmp, char c);
void	print_int(t_pattern tmp, va_list factor);
int	print(t_pattern tmp, va_list factor);
int	ft_search(char c, t_pattern tmp, va_list factor);
int	ft_parse(const char *format, int *i, t_pattern *tmp, va_list factor);
int	ft_printf(const char *format, ...);
char	*ft_itoa_base(long long int value, long int base);
void	ft_print_p(t_pattern tmp, unsigned long long int ptr);

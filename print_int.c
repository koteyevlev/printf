/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/06/30 21:21:42 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"


int	ft_num(const char *format, int *i, va_list factor)
{
	int at;
	
	at = 0;
	if (format[*i] == '*')
	{
		at = va_arg(factor, int);
		(*i)++;
		return (at);
	}
	else
	while(format[*i] >= '0' && format[*i] <= '9')
	{
		at = at*10 + (format[*i] - 48);
		(*i)++;
	}
	return(at);
}

void	put_cast(t_pattern *tmp, const char *format, int *i)
{
	if (format[*i] == 'h' && format[(*i) + 1] != 'h')
	{
		tmp->h = 1;
		(*i)++;
	}
	else if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		tmp->hh = 1;
		(*i) = (*i) + 2;
	}
	else if (format[*i] == 'l' && format[(*i) + 1] != 'l')
	{
		tmp->l = 1;
		(*i)++;
	}
	 else if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
	tmp->ll = 1;
	(*i) = (*i) + 2;
	}
}

void	addflag(t_pattern *tmp, char c)
{
	if (c == '+')
		tmp->plus = 1;
	else if (c == ' ')
		tmp->space = 1;
	else if (c == '-')
		tmp->minus = 1;
	else if (c == '#')
		tmp->hash = '1';
	else if (c == '0')
		tmp->zero = 1;
}

void	print_help (int pre, long long *digit)
{
	int num;
	
	if (*digit < 0)
		{
			ft_putchar('-');
			*digit = *digit * (-1);
		}
		
	num = pre - ft_countdigit(*digit);
	while (num-- > 0)
		ft_putnbr(0);
} 

long long	 va_arg_help(va_list factor, t_pattern *tmp)
{
	if (tmp->l == 1)
		return (va_arg(factor, long));
	else if (tmp->ll == 1)
		return (va_arg(factor, long long));
	else if (tmp->h == 1)
		return ((short)va_arg(factor, int));
	else if (tmp->hh == 1)
		return ((char)va_arg(factor, int));
	else
		return (va_arg(factor, int));
	
}

void	print_int(t_pattern tmp, va_list factor)
{
	long long digit;
	int s;
	int neg;
	
	neg = 0;
	digit = va_arg_help(factor, &tmp);
	if (digit < 0)
		neg = 1;
	if ((tmp.minus == 1) && (tmp.precision > ft_countdigit(digit)) && tmp.plus == 0)
		print_help (tmp.precision, &digit);
	if (tmp.minus == 1 && tmp.plus == 0)
		ft_putnbr(digit);
	if (tmp.width > ft_countdigit(digit))
	{
		if (tmp.precision > ft_countdigit(digit))
			tmp.width = tmp.width - (tmp.precision - ft_countdigit(digit));
		if (tmp.plus == 1 || neg == 1 || tmp.space == 1)
			neg = 1;
//		s = tmp.width - ft_countdigit(digit) - tmp.plus - tmp.space - neg;
		s = tmp.width - ft_countdigit(digit) - neg;
		if (tmp.zero == 1 && tmp.precision == -1)
			while (s-- > 0)
				ft_putchar('0');	
		else 
			while (s-- > 0)
				ft_putchar('@');
	}	
	if (tmp.plus == 1 && digit > 0)
			ft_putchar('+');
	else if (tmp.space == 1 && digit > 0)
			ft_putchar('&');
	if (tmp.minus == 0 && tmp.precision > ft_countdigit(digit))
		print_help (tmp.precision, &digit);
	if (tmp.minus == 0 || tmp.plus == 1)
		ft_putnbr(digit);
}


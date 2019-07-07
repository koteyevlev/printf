/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:28:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/03 20:55:57 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

void	print_c(t_pattern tmp, char c)
{
	int	s;
	s = tmp.width - 1;
	if (tmp.minus == 1)
	{
		ft_putchar(c);
		while (s-- > 0)
			ft_putchar(' ');

	}
	else
	{
		if (tmp.zero == 1)
		{
			while (s-- > 0)
				ft_putnbr(0);
			ft_putchar(c);
		}
		else
		{
		while (s-- > 0)
			ft_putchar(' ');
		ft_putchar(c);
		}
	}
}

void	print_s(t_pattern tmp, va_list factor)
{
	char *s;
	int len;
	char *str;
	char *leak;

//	printf("TEST0");
	s = va_arg(factor, char*);
	len = ft_strlen(s);
	if (tmp.precision < len && tmp.precision >= 0)
	{
		str = ft_strsub(s, 0, tmp.precision);
	}
	else 
	{
		str = ft_memalloc(1);
		leak = ft_strjoin(str, s);
		free (str);
		str = leak;
	}
	if (tmp.minus == 1)
		ft_putstr(str);
	len = ft_strlen(str);
	if (tmp.width > len)
	{
		len = tmp.width - len;
		if (tmp.zero == 1)
		{
			while (len-- > 0)
				ft_putchar('0');
		}
		else
			while (len-- > 0)
				ft_putchar(' ');
	}
	if (tmp.minus == 0)
		ft_putstr(str);
}

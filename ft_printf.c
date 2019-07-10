/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:53:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/07/10 16:18:37 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include "string.h"

void		new_pattern(t_pattern *tmp)
{
	tmp->hash = 0;
	tmp->L = 0;
	tmp->minus = 0;
	tmp->plus = 0;
	tmp->space = 0;
	tmp->zero = 0;
	tmp->width = 0;
	tmp->precision = -1;
	tmp->h = 0;
	tmp->hh = 0;
	tmp->l = 0;
	tmp->hh = 0;
	tmp->ll = 0;
	tmp->help = 0;
	tmp->type = 0;
}

int			ft_cast(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	else
		return (0);
}

int			type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' ||
		c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == 'f')
		return (1);
	else
		return (0);
}

int			ft_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int			print(t_pattern tmp, va_list factor)
{
	char c;
	
	if (tmp.type == 'd' || tmp.type == 'i' || tmp.type == 'D')
		print_int(tmp, factor);
	else if (tmp.type == 'u')
		print_u(tmp, factor);
	else if (tmp.type == 'c')
	{
		c = (va_arg(factor, int));
		print_c(tmp, c);
	}
	else if (tmp.type == 's')
		print_s(tmp, factor);
	else if (tmp.type == 'f' && tmp.L)
	{
		//printf("%Lf", va_arg(factor, long double));
		ft_print_f(tmp, va_arg(factor, long double));
	}
	else if (tmp.type == 'f')
		ft_print_f(tmp, va_arg(factor, double));
	else if (tmp.type == 'p' || tmp.type == 'x'
	|| tmp.type == 'X' || tmp.type == 'o')
		ft_print_p(tmp, va_arg(factor, intmax_t));
	return (0);
}

int	ft_search(char c, t_pattern tmp, va_list factor)
{
	int	count;

	count = 0;
	if (type(c) != 0)
	{
		tmp.type = c;
		print(tmp, factor);
		count++;
	}
	else if (ft_strindex("*0123456789.;# '+-hlL\0", c) < 0) // added flag '*'
	{
		tmp.type = 'c';
		print_c(tmp, c);
		count++;
	}
	return (count);
}

int	ft_parse(const char *format, int *i, t_pattern *tmp, va_list factor)
{
	while (ft_flag(format[*i]) != 0) // for multiple flags use 'while' 
		addflag(tmp, format[(*i)++]);
	if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '*')
		tmp->width = ft_num(format, i, factor); 
	if (format[*i] == '.')
	{
		(*i)++;
		tmp->precision = ft_num(format, i, factor);
	}
	if (ft_cast(format[*i]) != 0)
		{
		put_cast(tmp, format, i);
		}
	return (0);

	
}

int	ft_printf(const char *format, ...)
{
	int i = 0;
	t_pattern tmp;
	
	result = 0;
	va_list factor;
	va_start(factor, format);
	while (format[i] != 0)
	{
		if(format[i] == '%')
		{
			new_pattern(&tmp);
			i++;
			while (!ft_search(format[i], tmp, factor))
			{
				ft_parse(format, &i, &tmp, factor);
				if (format[i] == '\0')
					return (i);
			}
			i++;
		}
		if (format[i] == '\0')
			return (result);
		ft_putchar(format[i]);
		i++;
	}
	return (result);
}

/* int main()
{
	int res;

	res = printf("%+2.4d", -666);
	printf("\nres %d\n", res);

	res = ft_printf("%+2.4d", -666);
	printf("\nmy res %d\n", res);

	int test = 222;
	
	printf ("---------------------------\n"); 
	 printf ("TEST 1\n");
	res = ft_printf("%d\n", test);
	printf("my res %d\n", res);
	res = printf("%d\n", test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
//	printf("%d\n", 135);
//	ft_putstr("libft\n");
//	ft_putnbr(7);
	printf ("TEST 2\n"); 
	res = ft_printf("%-d\n", test); 
	printf("my res %d\n", res);
	res = printf("%-d\n", test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");  
	printf ("TEST 3\n"); 
	res = ft_printf("% d\n",test);
	printf("my res %d\n", res);
	res = printf("% d\n",test); 
	printf("res %d\n", res); 
	printf ("---------------------------\n"); 
	printf ("TEST 4\n"); 
	res = ft_printf("%+d\n",test);
	printf("my res %d\n", res);
	res = printf("%+d\n",test);
	printf("res %d\n", res);
	printf ("---------------------------\n");
	printf ("TEST 5\n");
	res = ft_printf("%-3d\n",test); 
	printf("my res %d\n", res);
	res = printf("%-3d\n",test); 
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	printf ("TEST 6\n");
	res = ft_printf("%3d\n",test);
	printf("my res %d\n", res);
	res = printf("%3d\n",test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	printf ("TEST 7\n");
	res = ft_printf("% 3d\n",test);
	printf("my res %d\n", res);
	res = printf("% 3d\n",test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	printf ("TEST 8\n"); 
	res = ft_printf("%+3d\n",test); 
	printf("my res %d\n", res);
	res = printf("%+3d\n",test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	 printf ("TEST 9\n");
	res = ft_printf("%4.2d\n",test); 
	printf("my res %d\n", res);
	res = printf("%4.2d\n",test); 
	printf("res %d\n", res); 
	printf ("---------------------------\n");  
	printf ("TEST 10\n");
	res = ft_printf("%-4.2d\n",test); 
	printf("my res %d\n", res);
	res = printf("%-4.2d\n",test); 
	printf("res %d\n", res); 
	printf ("---------------------------\n"); 
	printf ("TEST 11\n"); 
	res = ft_printf("%+4.2d\n",test);
	printf("my res %d\n", res);
	res = printf("%+4.2d\n",test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	printf ("TEST 12\n");
	res = ft_printf("% 4.2d\n",test);
  	printf("my res %d\n", res);	
	res = printf("% 4.2d\n",test); 
	res = printf("res %d\n", res); 	
	printf ("---------------------------\n");
	printf ("TEST 13\n");
	res = ft_printf("%2.4d\n",test);
    printf("my res %d\n", res);	
	res = printf("%2.4d\n",test); 
	printf("res %d\n", res); 
	printf ("---------------------------\n"); 
	printf ("TEST 14\n"); 
	res = ft_printf("%-2.4d\n",test);
    printf("my res %d\n", res);	
	res = printf("%-2.4d\n",test);
	printf("res %d\n", res); 
	 printf ("---------------------------\n"); 
	printf ("TEST 15\n"); 
	res = ft_printf("%+2.4d\n",test);
	printf("my res %d\n", res);
	res = printf("%+2.4d\n",test);
	printf("res %d\n", res); 
	printf ("---------------------------\n");
	 printf ("TEST 16\n");
	res = ft_printf("% 2.4d\n",test);
	printf("my res %d\n", res);
	res = printf("% 2.4d\n",test);
	printf("res %d\n", res);
} */

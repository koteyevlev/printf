/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:47:46 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 17:28:09 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <float.h>

char	*ft_sum(char *first, char *second)
{
	char	*new;
	int		i;
	int		um;

	if (!first)
		return (second);
	new = (char *)malloc(sizeof(char) * 4934);
	um = 0;
	i = 4932;
	new[4933] = '\0';
	while (i >= 0)
	{
		new[i] = (first[i] + second[i] - 96 + um) % 10 + 48;
		um = (first[i] + second[i] - 96 + um) / 10;
		i--;
	}
	return (new);
}

char	*ft_substract(char *first, char *second)
{
	char	*new;
	int		i;
	int		um;

	new = (char *)malloc(sizeof(char) * 4934);
	um = 0;
	i = 4932;
	new[4933] = '\0';
	while (i >= 0)
	{
		new[i] = ((10 + first[i] - second[i] + um) % 10) + 48;
		um = (10 + first[i] - second[i] + um) / 10 - 1;
		i--;
	}
	i = 0;
	while (new[i] >= '0' && new[i] <= '9')
		i++;
	if (i == 4933 && um >= 0)
		return (new);
	else
	{
		free(new);
		return (0);
	}
}

/* char	*ft_multstr(char *f, char *s)
{
	char	*new;
	int		i;
	int		j;
	int		carry;
	int		tmp;

	i = 0;
	new = (char *)malloc(sizeof(char) * 4934);
	while (i < 4933)
	{
		new[i] = '0';
		i++;
	}
	new[4933] = '\0';
	i = 4932;
	while (i >= 0)
	{
		carry = 0;
		j = 4932;
		while (j >= 0)
		{
			tmp = new[-(4932 - i - j)] - '0';
			new[-(4932 - i - j)] = (tmp + carry + (f[i] - '0') * (s[j] - '0')) % 10 + '0';
			carry = (tmp + carry + (f[i] - 48) * (s[j] - 48)) / 10;
			j--;
		}
		i--;
	}
	return (new);
} */

char	*ft_dividet(char *f)
{
	int		carry;
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * 4934);
	while (i < 4933)
	{
		new[i] = '0';
		i++;
	}
	new[4933] = '\0';
	carry = 0;
	i = 0;
	while (i < 4933)
	{
		new[i] = (f[i] - 48) / 2 + carry + 48;
		carry = (f[i] - 48) % 2 * 5;
		i++;
	}
	free(f);
	return (new);
}

char	*ft_multt(char *f)
{
	int		carry;
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * 4934);
	while (i < 4933)
	{
		new[i] = '0';
		i++;
	}
	new[4933] = '\0';
	carry = 0;
	i = 4932;
	while (i >= 0)
	{
		new[i] = ((f[i] - 48) * 2 + carry) % 10 + 48;
		carry = ((f[i] - 48) * 2 + carry) / 10;
		i--;
	}
	free(f);
	return (new);
}

char	*ft_stept(int step)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * 4934);
	i = -1;
	while (i++ < 4933)
		new[i] = '0';
	new[4933] = '\0';
	if (step >= 0)
		new[4932] = '1';
	else
		new[0] = '1';
	while (step > 0)
	{
		new = ft_multt(new);
		step--;
	}
	while (step < 0)
	{
		new = ft_dividet(new);
		step++;
	}
	return (new);
}

void	ft_print_krit2(t_pattern tmp, double nbr, int step, int index)
{
	if (tmp.plus && nbr == 1.0 / 0.0)
	{
		ft_putchar('+');
		index--;
	}
/*	else if (!tmp.minus && tmp.plus && nbr == -1.0 / 0.0) // ?
	{
		ft_putchar(' ');
		index--;
	} */
	if (nbr == 1.0 / 0.0 || nbr == -1.0 / 0.0)
		ft_putstr("inf");
	else if (step == 16384)
		ft_putstr("nan");
	while (tmp.minus && index > 3)
	{
		ft_putchar(' ');
		index--;
	}
}

void	ft_print_krit(t_pattern tmp, double nbr, int step)
{
	int	index;

	index = tmp.width;
	while (!tmp.minus && ((index > 4 && (nbr == -1. / 0. || tmp.plus)) ||
	((nbr != -1.0 / 0.0 && (!tmp.plus || nbr != 1.0 / 0.0)) && index > 3)))
	{
		ft_putchar(' ');
		tmp.space = 0;
		index--;
	}
	if (nbr == -1.0 / 0.0)
	{
		ft_putchar('-');
		index--;
	}
	if (nbr > 0 && (tmp.space || tmp.plus) && tmp.space && !tmp.plus)
	{
	//	if (tmp.plus)
	//		ft_putchar('+');
		if (tmp.space)
			ft_putchar(' ');
		index--;
	}
	ft_print_krit2(tmp, nbr, step, index);
}

char	*ft_zerostr(void)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * 4934);
	i = -1;
	while (i++ < 4933)
		new[i] = '0';
	new[4933] = '\0';
	return (new);
}

int		ft_notzero(char *str)
{
	while (*str && *str == '0')
		str++;
//	ft_putchar(*str);
	if (*str >= '1' && *str <= '9')
		return (1);
	else
		return (0);
}

void	ft_round(char **ost, char **ld, t_pattern tmp)
{
	char	*one;
	char	*tofree;
	int		i;

	if (tmp.precision > 4932)
		return ;
	if (ft_strindex("56789", (*ost)[tmp.precision + 1]) < 0)
	{
		(*ost)[tmp.precision + 1] = '\0';
		return ;
	}
	else
	{
		one = ft_zerostr();
		one[tmp.precision] = '1';
		tofree = *ost;
		i = 1;
		*ost = ft_sum(tofree, one);
		while ((*ost)[i] == '0' && tmp.precision >= i)
			i++;
		free(tofree);
		if (tmp.precision <= i)
		{
			one[tmp.precision] = '0';
			one[4932] = '1';
			if (ft_strindex("02468", (*ld)[4932]) >= 0 &&
			(*ost)[tmp.precision + 1] == '5' && !ft_notzero(*ost + 2))
				one[4932] = '0';
			tofree = *ld;
			(*ld) = ft_sum(tofree, one);
			free(tofree);
		}
		(*ost)[tmp.precision + 1] = '\0';
		free(one);
		return ;
	}
}

int		ft_sign(int nbr)
{
	if (nbr < 0)
		return (-1);
	else
		return (1);
}

void	ft_print_main2(t_pattern tmp, char **ld, char **ost, int byte)
{
	if (tmp.plus == 1)
		ft_putchar('+');
	else if (tmp.plus == 2)
		ft_putchar('-');
	else if (tmp.space && (tmp.width-- || 0 == 0))
		ft_putchar(' ');
	if (tmp.plus && byte < 4932 && (*ld)[byte] == '0')
		byte++;
	ft_putstr(&((*ld)[byte]));
	if (tmp.precision != 0 || tmp.hash) // bag with width, maybe dont work
		ft_putchar('.');
	else
		tmp.width++;
	ft_putstr(&((*ost)[1]));
	if (tmp.minus && tmp.plus)
		byte--;
	while (tmp.minus && (byte + tmp.width - tmp.precision - 4934) > 0)
	{
		ft_putchar(' ');
		byte = byte - ft_sign(byte + tmp.width - tmp.precision - 4934); //dont know
	}
}

void	ft_print_main(t_pattern tmp, char **ld, char **ost, int byte)
{
	if (!*ld)
		*ld = ft_zerostr();
	if (!*ost)
		*ost = ft_zerostr();
	if (tmp.precision < 0)
		tmp.precision = 6;
	ft_round(ost, ld, tmp);
	while (*ld && (*ld)[byte] == '0' && ((byte + tmp.width -
	tmp.precision - 4934) != 0 || tmp.minus) && byte < 4932)
		byte++;
	if (tmp.plus && (*ld)[byte] == '0' && byte < 4932 && !tmp.zero)
		byte++;
	if (!tmp.precision && ft_notzero(*ld) && tmp.width >= 4933 - byte)
		byte--;
	while (!tmp.zero && *ld && (*ld)[byte] == '0' && !tmp.minus && byte <= 4931)
	{
		ft_putchar(' ');
		tmp.space = 0;
		byte++;
	}
	ft_print_main2(tmp, ld, ost, byte);
	free(*ld);
	free(*ost);
}

char	*ft_sumdel(char **first, int step)
{
	char	*res;
	char	*second;

	second = ft_stept(step);
	if (!(*first))
		return (second);
	res = ft_sum(*first, second);
	if (*first)
		free(*first);
	if (second)
		free(second);
	return (res);
}

long double	ft_lmodul(long double nbr)
{
	if (nbr < 0.0)
		return (-nbr);
	return (nbr);
}

void	ft_print_f_help(t_pattern tmp, long double nbr, int byte)
{
	t_form_lf	n;
	int			step;
	char		*ld;
	char		*ost;

	if (nbr < +0.0 || 1.0 / nbr == -1.0 / 0.0)
		tmp.plus = 2;
	n.f = ft_lmodul(nbr);
	step = n.bytes.exponent - 16383;
	ost = 0;
	if (((ld = 0) != 0) || step >= 0)
		ld = ft_stept(step);
	else
		ost = ft_stept(step);
	while (byte--)
	{
		step--;
		if (step >= 0 && (n.bytes.mantisa >> byte & 1) == 1)
			ld = ft_sumdel(&ld, step);
		else if (step < 0 && (n.bytes.mantisa >> byte & 1) == 1)
			ost = ft_sumdel(&ost, step);
	}
	ft_print_main(tmp, &ld, &ost, 0);
}

void	ft_print_f(t_pattern tmp, long double nbr)
{
	int			i;
	int			byte;
	t_form_lf	n;
	int			step;

	n.f = nbr;
	step = n.bytes.exponent - 16383;
	i = 0;
	byte = 63;
	if (((double)nbr == 0.0 / 0.0 || (double)nbr == 1.0 / 0.0
	|| (double)nbr == -1.0 / 0.0) && !tmp.L)
	{
		ft_print_krit(tmp, (double)nbr, step);
		return ;
	}
	ft_print_f_help(tmp, nbr, byte);
}



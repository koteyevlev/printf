/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:17:58 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 20:29:29 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <float.h>

void	ft_print_krit2(t_pattern tmp, double nbr, int step, int index)
{
	if (tmp.plus && nbr == 1.0 / 0.0)
	{
		ft_putchar('+');
		index--;
	}
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
	if (*str >= '1' && *str <= '9')
		return (1);
	else
		return (0);
}

void	ft_roundthr(char **one, t_pattern tmp, char **ld, char **ost)
{
	(*one)[tmp.precision] = '0';
	(*one)[4932] = '1';
	if (ft_strindex("02468", (*ld)[4932]) >= 0 &&
	(*ost)[tmp.precision + 1] == '5' && !ft_notzero(*ost + 2))
		(*one)[4932] = '0';
}

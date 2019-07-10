/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:21:28 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 20:29:27 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <float.h>

void	ft_roundtwo(char **ost, t_pattern tmp, char **one, char **tofree)
{
	*one = ft_zerostr();
	(*one)[tmp.precision] = '1';
	*tofree = *ost;
	*ost = ft_sum(*tofree, *one);
	free(*tofree);
}

void	ft_round(char **ost, char **ld, t_pattern tmp)
{
	char	*one;
	char	*tofree;
	int		i;

	if (tmp.precision > 4932)
		return ;
	if (ft_strindex("56789", (*ost)[tmp.precision + 1]) < 0)
		(*ost)[tmp.precision + 1] = '\0';
	else
	{
		ft_roundtwo(ost, tmp, &one, &tofree);
		i = 1;
		while ((*ost)[i] == '0' && tmp.precision >= i)
			i++;
		if (tmp.precision <= i)
		{
			ft_roundthr(&one, tmp, ld, ost);
			tofree = *ld;
			(*ld) = ft_sum(tofree, one);
			free(tofree);
		}
		(*ost)[tmp.precision + 1] = '\0';
		free(one);
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
	if (tmp.precision != 0 || tmp.hash)
		ft_putchar('.');
	else
		tmp.width++;
	ft_putstr(&((*ost)[1]));
	if (tmp.minus && tmp.plus)
		byte--;
	while (tmp.minus && (byte + tmp.width - tmp.precision - 4934) > 0)
	{
		ft_putchar(' ');
		byte = byte - ft_sign(byte + tmp.width - tmp.precision - 4934);
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

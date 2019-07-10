/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:47:46 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 20:30:18 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <float.h>

char		*ft_sumdel(char **first, int step)
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

void		ft_print_f_help(t_pattern tmp, long double nbr, int byte)
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

void		ft_print_f(t_pattern tmp, long double nbr)
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

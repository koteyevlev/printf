/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:33:22 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/03 14:53:39 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigit(long long dig)
{
	int i;
	int num;
	int neg;

	i = 0;
	num = 1;
	neg = 1;
	if (dig < 0)
	{
		neg = -1 * neg;
		dig = -1 * dig;
	}
	while (dig > 9)
	{
		dig = dig / 10;
		num++;
	}
	return (num);
}

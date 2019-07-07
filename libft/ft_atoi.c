/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:22:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/03 17:14:49 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX 922337203685477580

int		ft_atoi(const char *str)
{
	unsigned int			i;
	int						neg;
	unsigned long long		num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = (-1) * neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if ((num > MAX || (num == MAX && str[i] - '0' > 7)) && neg == 1)
			return (-1);
		if ((num > MAX || (num == MAX && str[i] - '0' > 7)) && neg == -1)
			return (0);
	}
	return (num * neg);
}

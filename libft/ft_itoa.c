/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:09:50 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/03 14:54:13 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	int		i;
	int		cpy;
	char	*p;

	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = ((n < 0) ? -1 : 1);
	n = (n < 0) ? n * -1 : n * 1;
	cpy = n;
	while (n /= 10)
		i++;
	if (!(p = ft_memalloc(i + 1)))
		return (NULL);
	i--;
	while (i != -1)
	{
		p[i--] = cpy % 10 + 48;
		cpy = cpy / 10;
	}
	return (neg > 0 ? p : ft_strjoin("-", p));
}

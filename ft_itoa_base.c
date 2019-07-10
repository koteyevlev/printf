/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:05:41 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/09 21:18:57 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

long long int	ft_modul(long int nmr)
{
	if (nmr < 0)
		return (-nmr);
	return (nmr);
}

char			*ft_helpitoa(long long int value, long int base,
long long int len, long long int nbr)
{
	char	*res;
	char	*basestr;

	basestr = "0123456789abcdef";
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	while (nbr)
	{
		res[--len] = basestr[nbr % base];
		nbr = nbr / base;
	}
	if (value < 0)
		res[0] = '-';
	return (res);
}

char		*ft_itoa_base(long long int value, long int base)
{
	long long int		len;
	long long int		nbr;

	if (!value)
		return ("0");
	nbr = ft_modul(value);
	len = 0;
	while (nbr)
	{
		nbr = nbr / base;
		len++;
	}
	nbr = value;
	if (value < 0)
		len++;
	return (ft_helpitoa(value, base, len, nbr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:05:41 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 16:32:52 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

intmax_t		ft_modul(intmax_t nmr)
{
	if (nmr < 0 && nmr != ULLONG_MAX)
		return (-nmr);
	return (nmr);
}

char			*ft_helpitoa(intmax_t value, intmax_t base,
intmax_t len, intmax_t nbr)
{
	char	*res;
	char	*basestr;

	basestr = "0123456789abcdef";
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	if (nbr == ULLONG_MAX && base == 8)
		return (res = "1777777777777777777777");
	if (nbr == ULLONG_MAX && base == 16)
		return (res = "ffffffffffffffff");
	while (nbr)
	{
		res[--len] = basestr[nbr % base];
		nbr = nbr / base;
	}
	if (value < 0)
		res[0] = '-';
	return (res);
}

char		*ft_itoa_base(intmax_t value, long int base)
{
	intmax_t		len;
	intmax_t		nbr;

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

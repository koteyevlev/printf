/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 21:34:05 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/16 17:09:07 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *restrict src, int c, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;
	char		z;

	z = (char)c;
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		if (s[i] == z)
		{
			d[i] = s[i];
			return (dest + i + 1);
		}
		else
		{
			d[i] = s[i];
			i++;
		}
	}
	return (NULL);
}

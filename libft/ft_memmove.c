/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove-malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:42:58 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/06 17:37:57 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (pd <= ps || pd >= (ps + len))
	{
		while (len--)
			*pd++ = *ps++;
	}
	else
	{
		pd += len - 1;
		ps += len - 1;
		while (len--)
			*pd-- = *ps--;
	}
	return (dest);
}

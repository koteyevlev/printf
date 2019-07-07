/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:09:17 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/06 19:55:09 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t cd;
	size_t cs;
	size_t i;

	i = 0;
	cd = ft_strlen(dst);
	cs = ft_strlen(src);
	if (size == 0)
		return (cs);
	if (size <= cd)
		return (cs + size);
	while ((size - 1 > cd + i) && src[i] != '\0')
	{
		dst[cd + i] = src[i];
		i++;
	}
	dst[cd + i] = '\0';
	return (cd + cs);
}

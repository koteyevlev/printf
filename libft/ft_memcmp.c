/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:12:43 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/24 18:57:23 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *a, const void *b, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)a;
	s2 = (unsigned char *)b;
	i = 0;
	while (n > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		n--;
		i++;
	}
	return (0);
}

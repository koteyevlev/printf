/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:08:35 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/24 13:24:51 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	b;

	i = 0;
	b = (char)c;
	while (str[i] != b)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

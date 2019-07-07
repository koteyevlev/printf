/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:08:35 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/24 14:00:11 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	b;
	int				len;

	b = (char)c;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == b)
			return ((char *)str + len);
		len--;
	}
	return (NULL);
}

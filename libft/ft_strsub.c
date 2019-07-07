/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:26:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/21 21:50:43 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s == NULL)
		return (NULL);
	p = ft_strnew(len);
	if (p == NULL)
		return (NULL);
	while (i < len)
		p[i++] = s[start++];
	return (p);
}

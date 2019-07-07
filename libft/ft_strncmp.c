/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:29:56 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/21 20:23:18 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)a;
	s2 = (unsigned char *)b;
	if (n == 0)
		return (0);
	n--;
	i = 0;
	while (s1[i] == s2[i] && n > i && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] == '\0')
		return (-1);
	else if (s2[i] == '\0')
		return (1);
	else
		return (s1[i] - s2[i]);
}

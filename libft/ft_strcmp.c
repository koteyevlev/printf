/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:29:56 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/06 17:05:37 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *a, const char *b)
{
	int					i;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)a;
	s2 = (unsigned char *)b;
	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
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

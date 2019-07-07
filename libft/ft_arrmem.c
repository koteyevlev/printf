/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:41:54 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/21 18:54:16 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrmem(char const *str, int index, char c)
{
	char	*arr;
	int		count;
	int		word;

	word = 0;
	while (*str != '\0')
	{
		count = 0;
		if (*str == c)
			str++;
		else
		{
			while (*str != '\0' && *str != c)
			{
				str++;
				count++;
			}
			word++;
			if (word == index)
				arr = (char *)malloc(sizeof(char) * count + 1);
		}
	}
	return (NULL);
}

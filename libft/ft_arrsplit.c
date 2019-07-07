/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:47:19 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/09 20:31:14 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrsplit(char const *str, int count, char **arr, char c)
{
	int i;
	int arr_i;
	int len;

	arr_i = 0;
	i = 0;
	while (str[i] != '\0' && arr_i < count)
	{
		len = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			len++;
		}
		arr[arr_i] = ft_strsub(str, i - len, len);
		arr_i++;
	}
	arr[arr_i] = NULL;
	if (arr == NULL)
		return (NULL);
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:06:34 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/05 15:31:43 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*arr;
	size_t	i;

	i = 0;
	arr = (void *)malloc(sizeof(void) * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, size);
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:44:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/21 17:01:58 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char c;

	if (s == NULL)
		return ;
	c = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}

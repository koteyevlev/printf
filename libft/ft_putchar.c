/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:37:26 by wtorwold          #+#    #+#             */
/*   Updated: 2019/06/30 17:58:46 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf.h"

void	ft_putchar(char c)
{
	static int res = 0;
	res++;
	write(1, &c, 1);
	result = res;
}

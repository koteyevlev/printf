/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:13:19 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 20:14:27 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <limits.h>

void	ft_strcapitalize(char **str, intmax_t nmr)
{
	int	index;

	index = 0;
	if (nmr == ULLONG_MAX)
		*str = "FFFFFFFFFFFFFFFF";
	while ((*str)[index])
	{
		if ((*str)[index] >= 'a' && (*str)[index] <= 'z')
			(*str)[index] = (*str)[index] - 'a' + 'A';
		index++;
	}
}

void	ft_privedenie(t_pattern tmp, intmax_t *ptr)
{
	if (tmp.type == 'p' || tmp.ll)
		return ;
	if (tmp.l)
		*ptr = (unsigned long int)(*ptr);
	else if (tmp.h)
		*ptr = (unsigned short int)(*ptr);
	else if (tmp.hh)
		*ptr = (unsigned char)(*ptr);
	else if (!tmp.ll)
		*ptr = (unsigned int)(*ptr);
}

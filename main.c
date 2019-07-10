/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:14 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 16:01:38 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <float.h>
#include <limits.h>

int main()
{
	int res;

	res = ft_printf("%.o|%-.o|%#.o|%0.o", 0U, 0U, 0U, 0U);
	printf("\nmy res %d\n", res);
	res = printf("%.o|%-.o|%#.o|%0.o", 0U, 0U, 0U, 0U);
	printf("\nprintf res %d\n", res);
}
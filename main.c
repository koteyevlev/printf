/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:14 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 18:56:16 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <float.h>
#include <limits.h>

int main()
{
	int res;

	res = ft_printf("%.4932llf", DBL_MAX);
	printf("\nmy res %d\n", res);
	//res = printf("%lld", −9223372036854775808);
//	printf("\nprintf res %d\n", res);
}
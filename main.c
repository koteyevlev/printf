/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:14 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 17:24:12 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <float.h>
#include <limits.h>

int main()
{
	int res;

	res = ft_printf("%-#23.5hhX|%-023.5hhX|%#023.5hhX|%-#023.5hhX", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	printf("\nmy res %d\n", res);
	res = printf("%-#23.5hhX|%-023.5hhX|%#023.5hhX|%-#023.5hhX", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	printf("\nprintf res %d\n", res);
}
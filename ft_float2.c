/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:15:30 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/10 20:16:15 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include "printf.h"
#include <float.h>

char	*ft_sum(char *first, char *second)
{
	char	*new;
	int		i;
	int		um;

	if (!first)
		return (second);
	new = (char *)malloc(sizeof(char) * 4934);
	um = 0;
	i = 4932;
	new[4933] = '\0';
	while (i >= 0)
	{
		new[i] = (first[i] + second[i] - 96 + um) % 10 + 48;
		um = (first[i] + second[i] - 96 + um) / 10;
		i--;
	}
	return (new);
}

char	*ft_substract(char *first, char *second)
{
	char	*new;
	int		i;
	int		um;

	new = (char *)malloc(sizeof(char) * 4934);
	um = 0;
	i = 4932;
	new[4933] = '\0';
	while (i >= 0)
	{
		new[i] = ((10 + first[i] - second[i] + um) % 10) + 48;
		um = (10 + first[i] - second[i] + um) / 10 - 1;
		i--;
	}
	i = 0;
	while (new[i] >= '0' && new[i] <= '9')
		i++;
	if (i == 4933 && um >= 0)
		return (new);
	else
	{
		free(new);
		return (0);
	}
}

char	*ft_dividet(char *f)
{
	int		carry;
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * 4934);
	while (i < 4933)
	{
		new[i] = '0';
		i++;
	}
	new[4933] = '\0';
	carry = 0;
	i = 0;
	while (i < 4933)
	{
		new[i] = (f[i] - 48) / 2 + carry + 48;
		carry = (f[i] - 48) % 2 * 5;
		i++;
	}
	free(f);
	return (new);
}

char	*ft_multt(char *f)
{
	int		carry;
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * 4934);
	while (i < 4933)
	{
		new[i] = '0';
		i++;
	}
	new[4933] = '\0';
	carry = 0;
	i = 4932;
	while (i >= 0)
	{
		new[i] = ((f[i] - 48) * 2 + carry) % 10 + 48;
		carry = ((f[i] - 48) * 2 + carry) / 10;
		i--;
	}
	free(f);
	return (new);
}

char	*ft_stept(int step)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * 4934);
	i = -1;
	while (i++ < 4933)
		new[i] = '0';
	new[4933] = '\0';
	if (step >= 0)
		new[4932] = '1';
	else
		new[0] = '1';
	while (step > 0)
	{
		new = ft_multt(new);
		step--;
	}
	while (step < 0)
	{
		new = ft_dividet(new);
		step++;
	}
	return (new);
}

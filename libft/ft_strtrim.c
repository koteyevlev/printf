/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:57:04 by wtorwold          #+#    #+#             */
/*   Updated: 2019/02/06 16:52:59 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	int		len;
	char	*p;

	if (!s)
		return (0);
	begin = 0;
	len = (int)ft_strlen(s);
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	end = len - 1;
	while ((end > begin) && (s[end] == ' ' || s[end] == '\n'
				|| s[end] == '\t'))
		end--;
	if (begin > end)
		return ((char *)ft_memalloc(1));
	len = end - begin + 1;
	p = ft_strsub(s, begin, len);
	return (p);
}

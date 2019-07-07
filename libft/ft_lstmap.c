/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:04:57 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/18 20:57:36 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *newlist;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	if (!temp)
		return (NULL);
	newlist = temp;
	while (lst->next)
	{
		temp->next = f(lst->next);
		if (!temp->next)
			return (NULL);
		lst = lst->next;
		temp = temp->next;
	}
	return (newlist);
}

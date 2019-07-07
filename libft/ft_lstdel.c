/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:16:23 by wtorwold          #+#    #+#             */
/*   Updated: 2019/01/18 20:51:44 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;

	while (*alst != NULL)
	{
		temp = (*alst);
		*alst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = NULL;
	}
}

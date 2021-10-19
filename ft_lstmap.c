/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillow <swillow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:05:01 by swillow           #+#    #+#             */
/*   Updated: 2021/05/13 22:22:16 by swillow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	ptr = new_list;
	if (new_list == NULL)
		ft_lstclear(&lst, del);
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		new_list = new_list->next;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillow <swillow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:55:57 by swillow           #+#    #+#             */
/*   Updated: 2021/05/09 14:56:25 by swillow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if ((*lst) == NULL || lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((ptr)->next != NULL)
		(ptr) = (ptr)->next;
	(ptr)->next = new;
}

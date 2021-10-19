/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillow <swillow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:13:26 by swillow           #+#    #+#             */
/*   Updated: 2021/05/08 11:05:41 by swillow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (s1);
}

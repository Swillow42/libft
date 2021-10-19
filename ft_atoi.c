/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillow <swillow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:34:42 by swillow           #+#    #+#             */
/*   Updated: 2021/05/09 13:38:12 by swillow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		rus;
	int		sig;
	long	num;

	rus = 0;
	sig = 1;
	num = 0;
	while (str[rus] == ' ' || (str[rus] >= 9 && str[rus] <= 13))
		rus++;
	if (str[rus] == '+' || str[rus] == '-')
		if (str[rus++] == '-')
			sig = -1;
	while (str[rus] > 47 && str[rus] < 58)
	{
		if (num > 2147483647)
		{
			if (sig < 0)
				return (0);
			else
				return (-1);
		}
		num = num * 10 + (str[rus] - 48);
		rus++;
	}
	return (sig * num);
}		

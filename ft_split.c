/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillow <swillow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:22:17 by swillow           #+#    #+#             */
/*   Updated: 2021/04/30 10:54:14 by swillow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_free(char **mass)
{
	unsigned int	i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	free(mass);
	return (NULL);
}

static unsigned int	ft_lines(char const *s, char c)
{
	unsigned int	i;
	unsigned int	n_lines;

	n_lines = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			n_lines++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (i != 0 && s[i - 1] != c)
		n_lines++;
	return (n_lines);
}

static void	ft_new_str(char **str, unsigned int *str_len, char c)
{
	unsigned int	i;

	*str = *str + *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	str_len;
	unsigned int	i;
	char			**mass;
	char			*str;

	if (!s)
		return (NULL);
	mass = malloc(sizeof(char *) * (ft_lines(s, c) + 1));
	if (!mass)
		return (NULL);
	str = (char *) s;
	str_len = 0;
	i = 0;
	while (i < ft_lines(s, c))
	{
		ft_new_str(&str, &str_len, c);
		mass[i] = malloc(sizeof(char) * (str_len + 1));
		if (!mass[i])
			return (ft_malloc_free(mass));
		ft_strlcpy(mass[i], str, str_len + 1);
		i++;
	}
	mass[i] = NULL;
	return (mass);
}

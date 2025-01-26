/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:33:21 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/24 18:02:08 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sl;
	char	*p;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (start >= sl)
		len = 0;
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < len && s[start])
		{
			p[i] = s[start];
			i++;
			start++;
		}
		p[i] = '\0';
	}
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_isint(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!s[i])
			return (1);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i])
			return (1);
	}
	return (0);
}

long	ft_atoi(const char *s)
{
	int		i;
	int		is_neg;
	long	n;

	i = 0;
	is_neg = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			is_neg = 1;
		i++;
	}
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + s[i] - '0';
		i++;
	}
	if (n && is_neg)
		return (-n);
	return (n);
}

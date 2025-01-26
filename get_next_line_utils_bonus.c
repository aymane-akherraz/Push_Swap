/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:04:56 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/21 15:52:15 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	i;
	size_t	j;
	size_t	len;
	char	*p;

	l1 = ft_strlen(s1);
	len = l1 + ft_strlen(s2);
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < l1)
		{
			p[i] = s1[i];
			i++;
		}
		j = 0;
		while (i < len)
			p[i++] = s2[j++];
		p[i] = '\0';
	}
	return (p);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = ft_strlen(s);
	p = malloc(len + 1);
	if (p)
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakherra <aakherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:58:50 by aakherra          #+#    #+#             */
/*   Updated: 2025/01/25 09:20:29 by aakherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_header_bonus.h"

char	*check_reminder(char **buf, char **rb)
{
	char	*line;

	line = NULL;
	if (*buf && **buf)
		line = ft_strdup(*buf);
	free(*rb);
	free(*buf);
	*rb = NULL;
	*buf = NULL;
	return (line);
}

char	*get_line(char **buf, char **rb)
{
	char	*r;
	char	*n;
	char	*line;

	line = NULL;
	n = ft_strchr(*buf, '\n');
	if (n)
	{
		line = ft_substr(*buf, 0, (n - *buf) + 1);
		r = ft_strdup(n + 1);
		free(*buf);
		*buf = r;
		free(*rb);
	}
	return (line);
}

void	handle_bufs(char **n, char *buf)
{
	char	*new_buf;

	if (*n)
	{
		new_buf = ft_strjoin(*n, buf);
		free(*n);
		*n = new_buf;
	}
	else
		*n = ft_strdup(buf);
}

char	*get_next_line(int fd, int empty)
{
	char					*buffer;
	char					*l;
	ssize_t					nb;
	static char				*n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	l = get_line(&n, &buffer);
	if (l)
		return (l);
	if (!empty)
		nb = read(fd, buffer, BUFFER_SIZE);
	else
		nb = 0;
	while (nb > 0)
	{
		buffer[nb] = '\0';
		handle_bufs(&n, buffer);
		l = get_line(&n, &buffer);
		if (l)
			return (l);
		nb = read(fd, buffer, BUFFER_SIZE);
	}
	return (check_reminder(&n, &buffer));
}

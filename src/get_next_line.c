/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:42:50 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 19:25:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

char	*next_line(char *buffer)
{
	char	*tmp;

	tmp = ft_strchr_gnl(buffer, '\n') + 1;
	if (ft_strlen_gnl(tmp) > 0)
	{
		tmp = ft_strdup_gnl(tmp);
	}
	else
	{
		tmp = NULL;
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	return (tmp);
}

int	ft_found_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	if (i > 0)
		return (2);
	return (0);
}

char	*ft_read(int fd, char *buffer, int *bytes_read)
{
	char	frag[BUFFER_SIZE + 1];
	char	*tmp;

	if (read(fd, 0, 0) < 0)
	{
		free (buffer);
		return (NULL);
	}
	*bytes_read = read(fd, frag, BUFFER_SIZE);
	if (*bytes_read > 0)
		frag[*bytes_read] = '\0';
	if (*bytes_read <= 0)
	{
		if (buffer)
			return (buffer);
		return (NULL);
	}
	if (!buffer)
		tmp = ft_strdup_gnl(frag);
	else
	{
		tmp = ft_strjoin_gnl(buffer, frag);
		free(buffer);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			has_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (line = NULL);
	buffer = ft_read(fd, buffer, &bytes_read);
	if (buffer == NULL)
		return (NULL);
	has_line = ft_found_line(buffer);
	if (has_line == 1)
	{
		line = ft_substr_gnl(buffer);
		if (!line)
			return (free(buffer), buffer = NULL, NULL);
		return (buffer = next_line(buffer), line);
	}
	if (has_line == 2 && bytes_read < BUFFER_SIZE)
	{
		line = ft_strdup_gnl(buffer);
		return (free(buffer), buffer = NULL, line);
	}
	return (get_next_line(fd));
}

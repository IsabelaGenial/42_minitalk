/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:32:38 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 04:50:50 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_read(int fd, char *rest);
static char		*ft_get_line(char *temp_buffer);
static char		*ft_get_rest(char *temp_buffer);

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read(fd, rest);
	if (!rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_get_line(rest);
	rest = ft_get_rest(rest);
	return (line);
}

static char	*ft_read(int fd, char *rest)
{
	char	*temp_buffer;
	char	*freealloc;
	int		bytes_read;

	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read || rest)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		freealloc = rest;
		temp_buffer[bytes_read] = '\0';
		rest = ft_strjoin (rest, temp_buffer);
		free(freealloc);
		if (ft_strchr(rest, '\n') || bytes_read <= 0)
			break ;
	}
	free(temp_buffer);
	if (bytes_read < 0)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static char	*ft_get_line(char *temp_buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (temp_buffer[i] != '\n' && temp_buffer[i])
			i++;
	line = ft_substr(temp_buffer, 0, i);
	return (line);
}

static char	*ft_get_rest(char *temp_buffer)
{
	char	*buffer;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (temp_buffer[i] != '\n' && temp_buffer[i])
			i++;
	if (!temp_buffer[i] || temp_buffer[i + 1] == '\0')
	{
		free(temp_buffer);
		return (NULL);
	}		
	buffer = ft_calloc((ft_strlen(&temp_buffer[++i]) + 1), sizeof(char));
	j = 0;
	while (temp_buffer[i] != '\0')
		buffer[j++] = temp_buffer[i++];
	free(temp_buffer);
	return (buffer);
}

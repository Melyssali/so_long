/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:50:48 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/15 15:59:22 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*join_buffer(char *static_buffer, char *buffer, int bytes_read)
{
	char	*temp;

	if (!static_buffer)
	{
		static_buffer = malloc(ft_strlen_gnl(buffer) + 1);
		if (!static_buffer)
			return (0);
		static_buffer[0] = '\0';
	}
	temp = static_buffer;
	static_buffer = ft_strjoin_gnl(static_buffer, buffer, bytes_read);
	free(temp);
	return (static_buffer);
}

char	*get_end_of_line(char *static_buffer)
{
	char	*end_line;
	int		i;
	int		j;
	size_t	static_buffer_size;

	i = 0;
	j = 0;
	static_buffer_size = ft_strlen_gnl(static_buffer);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (static_buffer[i] == '\n')
		i++;
	if (static_buffer_size - i == 0)
	{
		free(static_buffer);
		return (0);
	}
	end_line = malloc((static_buffer_size - i) + 1);
	if (!end_line)
		return (0);
	while (static_buffer[i])
		end_line[j++] = static_buffer[i++];
	end_line[j] = '\0';
	free(static_buffer);
	return (end_line);
}

char	*get_read_line(char *static_buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!static_buffer)
		return (0);
	if (ft_strchr_gnl(static_buffer, '\n'))
		i = (ft_strchr_gnl(static_buffer, '\n') - static_buffer + 1);
	else
		i = ft_strlen_gnl(static_buffer);
	new_line = malloc(i + 1);
	if (!new_line)
		return (0);
	ft_strlcpy_gnl(new_line, static_buffer, i);
	return (new_line);
}

char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr_gnl(static_buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buffer);
			free(buffer);
			return (0);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		static_buffer = join_buffer(static_buffer, buffer, bytes_read);
	}
	free(buffer);
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	static_buffer = read_line(static_buffer, fd);
	if (!static_buffer || static_buffer[0] == '\0')
		return (NULL);
	line = get_read_line(static_buffer);
	static_buffer = get_end_of_line(static_buffer);
	return (line);
}

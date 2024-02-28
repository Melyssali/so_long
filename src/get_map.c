/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:53 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:25:25 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <errno.h>
#include <libft.h>
#include <string.h>
#include <unistd.h>

char	**split_line_joined(char *file);

char	*read_and_join(char *file)
{
	int		fd;
	char	*line;
	char	*line_to_join;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	line_to_join = malloc(1);
	if (!line_to_join)
		return (NULL);
	line_to_join[0] = '\0';
	while (line)
	{
		line_to_join = ft_strjoin_libft(line_to_join, line);
		if (!line_to_join)
		{
			close(fd);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_to_join);
}

char	**split_line_joined(char *file)
{
	char	**map;
	char	*line_joined;

	map = malloc(1);
	if (!map)
		return (NULL);
	line_joined = read_and_join(file);
	map = ft_split(line_joined, '\n');
	free(line_joined);
	return (map);
}

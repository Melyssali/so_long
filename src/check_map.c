/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:16:09 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:23:40 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

int	compare_lines_length(char **map_temp, t_game_data *game)
{
	int	y;
	int	previous_line;

	y = 1;
	previous_line = 0;
	while (y < game->map.count_lines - 1
		&& ft_strlen(map_temp[previous_line]) == ft_strlen(map_temp[y]))
	{
		y++;
		previous_line++;
	}
	if (ft_strlen(map_temp[y]) != ft_strlen(map_temp[previous_line]))
	{
		ft_printf("lines don't have same length");
		return (1);
	}
	return (0);
}

int	is_rectangle(t_game_data *game)
{
	if (game->map.line_length == game->map.count_lines)
	{
		ft_printf("map is not rectangle");
		return (1);
	}
	else
		return (0);
}

int	is_encircled_by_trees(char **map_temp, t_game_data *game)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (map_temp[++y])
	{
		while (map_temp[0][x] && map_temp[game->map.count_lines - 1][x])
		{
			if (map_temp[0][x] != '1' || map_temp[game->map.count_lines
				- 1][x] != '1')
			{
				ft_printf("Map is not surrounded by trees\n");
				return (1);
			}
			x++;
		}
		if (map_temp[y][0] != '1' || map_temp[y][game->map.line_length
			- 1] != '1')
		{
			ft_printf("Map is not surrounded by trees\n");
			return (1);
		}
	}
	return (0);
}

void	flood_fill(t_game_data *game, int x, int y,
		char visited)
{
	if (x <= 0 || y <= 0 || x >= (int)strlen(game->map.map_temp[y]) - 1
		|| y >= game->map.count_lines - 1)
		return ;
	if (game->map.map_temp[y][x] == visited)
		return ;
	if (game->map.map_temp[y][x] == '1')
		return ;
	if (game->map.map_temp[y][x] == 'C')
		game->map.to_collect += 1;
	if (game->map.map_temp[y][x] == 'E')
	{
		game->map.exit_reachable += 1;
		game->map.map_temp[y][x] = visited;
		return ;
	}
	game->map.map_temp[y][x] = visited;
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x, y + 1, visited);
	flood_fill(game, x, y - 1, visited);
}

void	render_error(int error)
{
	if (error == 1)
	{
		perror("Error\n, lines are not same length.\n");
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		perror("Error\n, map is not rectangle.\n");
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		perror("Error\n, map is encircled by trees.\n");
		exit(EXIT_FAILURE);
	}
	if (error == 4)
	{
		perror("Error\n, path not accessible or collectible not reachable.\n");
		exit(EXIT_FAILURE);
	}
}

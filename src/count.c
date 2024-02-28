/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:38:22 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:23:40 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <libft.h>
#include <stdlib.h>

void	count_exits_collectibles_players(char **map_temp, t_game_data *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	game->map.exits_count = 0;
	game->map.players_in_map = 0;
	game->map.c_count = 0;
	while (map_temp[++y])
	{
		while (map_temp[y][++x])
		{
			if (map_temp[y][x] == 'E')
				game->map.exits_count++;
			else if (map_temp[y][x] == 'P')
			{
				game->map.x = x;
				game->map.y = y;
				game->map.players_in_map++;
			}
			else if (map_temp[y][x] == 'C')
				game->map.c_count++;
		}
		x = -1;
	}
}

void	count_lines_func(char **map_temp, t_game_data *game)
{
	int	y;

	y = 0;
	game->map.count_lines = 0;
	while (map_temp[y])
		y++;
	game->map.count_lines = y;
}

void	count_line_length(char **map_temp, t_game_data *game)
{
	int	y;

	y = 0;
	game->map.line_length = 0;
	if (!map_temp)
	{
		perror("Map doesn't exist bro");
		return ;
	}
	game->map.line_length = ft_strlen(map_temp[y]);
}

int	count_and_check(char **map_temp, t_game_data *game)
{
	game->map.to_collect = 0;
	game->map.exit_reachable = 0;
	game->map.error = 0;
	if (!game->map.map_temp)
	{
		perror("PAS DE MAP");
		return (EXIT_FAILURE);
	}
	count_exits_collectibles_players(map_temp, game);
	count_lines_func(map_temp, game);
	count_line_length(map_temp, game);
	if (compare_lines_length(map_temp, game) == 1)
		game->map.error = 1;
	if (is_rectangle(game) == 1)
		game->map.error = 2;
	if (is_encircled_by_trees(map_temp, game) == 1)
		game->map.error = 3;
	flood_fill(game, game->map.x, game->map.y, 'V');
	if (game->map.to_collect < 1
		|| game->map.exit_reachable != 1
		|| game->map.c_count != game->map.to_collect)
		game->map.error = 4;
	return (game->map.error);
}

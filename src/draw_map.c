/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:53 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:31:09 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <MLX42.h>
#include <stdlib.h>

int	drawing_map(char **map, t_game_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_image_to_window(game->mlx, game->img_grass, x * 32, y * 32);
			if (map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_tree, x * 32, y * 32);
			if (map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->img_char, x * 32, y * 32);
			if (map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->img_collectible, x * 32, y
					* 32);
			if (map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

void	change_map(char **map, t_game_data *game, int y, int x)
{
	if (y >= 0 && y < game->map.count_lines && x >= 0
		&& x < game->map.line_length)
	{
		if ((map[y][x] == '0' || map[y][x] == 'C'
			|| map[y][x] == 'E') && map[y][x] != '1'
			&& map[game->map.y][game->map.x] == 'P')
		{
			if (map[y][x] == 'C')
				game->map.collected += 1;
			if (map[y][x] == 'E' && game->map.collected
			== game->map.to_collect)
			{
				mlx_close_window(game->mlx);
				exit(EXIT_SUCCESS);
			}
			if (map[y][x] != 'E')
			{
				map[game->map.y][game->map.x] = '0';
				map[y][x] = 'P';
				game->map.y = y;
				game->map.x = x;
			}
		}
	}
}

int	redraw_map(char **map, t_game_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->img_char, x * 32, y
						* 32) < 0)
					return (EXIT_FAILURE);
			}
			if (map[y][x] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->img_collectible, x
						* 32, y * 32) < 0)
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

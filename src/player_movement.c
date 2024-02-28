/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:53 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:23:53 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <MLX42.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

void	handle_movement(t_game_data *game, int y, int x, char *img_path)
{
	game->map.img_path = img_path;
	mlx_delete_image(game->mlx, game->img_char);
	mlx_delete_xpm42(game->character);
	mlx_delete_image(game->mlx, game->img_collectible);
	mlx_delete_xpm42(game->collectible);
	load_images(game, game->map.img_path);
	change_map(game->map.map, game, y, x);
	redraw_map(game->map.map, game);
	show_movements(game);
	count_pokeballs(game);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game_data	*game;
	int			x;
	int			y;

	game = param;
	x = game->map.x;
	y = game->map.y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		handle_movement(game, y -= 1, x, IMG_UP);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		handle_movement(game, y += 1, x, IMG_DOWN);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		handle_movement(game, y, x -= 1, IMG_LEFT);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		handle_movement(game, y, x += 1, IMG_RIGHT);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		game->map.movement += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:53 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:23:53 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

void	init(char **map, int width, int height, t_game_data *game)
{
	game->map.movement = 0;
	game->map.collected = 0;
	if (!map)
	{
		perror("ya pas");
		return ;
	}
	game->map.img_path = IMG_DOWN;
	game->mlx = mlx_init(width, height, "My Pokemon-like game", false);
	if (!game->mlx)
	{
		perror("là, y'a un problème avec mlx");
		return ;
	}
	load_images(game, game->map.img_path);
	drawing_map(map, game);
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

int	load_images(t_game_data *game, char *img_path)
{
	game->tree = mlx_load_xpm42("./assets/xpm3/tree-2.xpm42");
	game->img_tree = mlx_texture_to_image(game->mlx, &game->tree->texture);
	game->grass = mlx_load_xpm42("./assets/xpm3/grass.xpm42");
	game->img_grass = mlx_texture_to_image(game->mlx, &game->grass->texture);
	game->character = mlx_load_xpm42(img_path);
	game->img_char = mlx_texture_to_image(game->mlx, &game->character->texture);
	game->collectible = mlx_load_xpm42("./assets/xpm3/pokeball.xpm42");
	game->img_collectible = mlx_texture_to_image(game->mlx,
			&game->collectible->texture);
	game->exit = mlx_load_xpm42("./assets/xpm3/echelle.xpm42");
	game->img_exit = mlx_texture_to_image(game->mlx, &game->exit->texture);
	if (!game->tree || !game->img_tree || !game->grass || !game->img_grass
		|| !game->character || !game->img_char || !game->collectible
		|| !game->img_collectible || !game->exit || !game->img_exit)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

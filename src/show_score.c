/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:14:37 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:23:53 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <MLX42.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

void	show_movements(t_game_data *game)
{
	char	*count_score;
	char	*score_string;
	char	*movement_num;

	score_string = "Movement count : ";
	count_score = ft_itoa(game->map.movement);
	movement_num = ft_strjoin_libft(score_string, count_score);
	if (game->img_string)
		mlx_delete_image(game->mlx, game->img_string);
	game->img_string = mlx_put_string(game->mlx, movement_num, 5, 3);
	ft_printf("Movement : %s \n", movement_num);
}

void	count_pokeballs(t_game_data *game)
{
	char	*count_poke;
	char	*pokeball_string;
	char	*poke_accessibles;
	char	*pokeballs_collected;

	pokeball_string = "Pokeballs collected: ";
	count_poke = ft_itoa(game->map.collected);
	poke_accessibles = ft_itoa(game->map.to_collect);
	pokeballs_collected = ft_strjoin_libft(pokeball_string, count_poke);
	pokeballs_collected = ft_strjoin_libft(pokeballs_collected, "/");
	pokeballs_collected = ft_strjoin_libft(pokeballs_collected,
			poke_accessibles);
	if (game->poke_string)
		mlx_delete_image(game->mlx, game->poke_string);
	game->poke_string = mlx_put_string(game->mlx, pokeballs_collected, 5, 20);
}

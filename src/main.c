/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:53 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:13:02 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/so_long.h"
#include <libft.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game_data	game;

	game.map.error = 0;
	if (argc == 2)
	{
		game.map.map = split_line_joined(argv[1]);
		game.map.map_temp = split_line_joined(argv[1]);
		game.map.error = count_and_check(game.map.map_temp, &game);
		render_error(game.map.error);
		init(game.map.map, game.map.line_length * 32, game.map.count_lines * 32,
			&game);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

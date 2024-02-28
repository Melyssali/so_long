/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:31:58 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:26:51 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_UP "assets/xpm3/main_up.xpm42"
# define IMG_DOWN "assets/xpm3/main_down.xpm42"
# define IMG_LEFT "assets/xpm3/main_left.xpm42"
# define IMG_RIGHT "assets/xpm3/main_right.xpm42"
#include <MLX42.h>

typedef struct s_map 
{
	char 	**map;
	char 	**map_temp;
	char 	*img_path;
	int		x;
	int		y;
    int 	c_count;
	int		exits_count;
    int 	players_in_map;
	int		count_lines;
	int		collected;
	int		exit_reachable;
	int		to_collect;
	int		movement;
	int		line_length;
	int 	error;
} t_map;

typedef struct s_game_data 
{
	mlx_t *mlx;
	xpm_t *tree;
	xpm_t *grass;
	xpm_t *character;
	xpm_t *collectible;
	xpm_t *exit;
	mlx_image_t *img_tree;
	mlx_image_t *img_grass;
	mlx_image_t *img_char;
	mlx_image_t *img_collectible;
	mlx_image_t *img_exit;
	mlx_image_t *img_string;
	mlx_image_t *poke_string;
	t_map map;
} t_game_data;

char    *read_and_join(char *file);
char    **split_line_joined(char *file);
int		count_and_check(char **map_temp, t_game_data *game);
void	count_exits_collectibles_players(char **map_temp, t_game_data *game);
void	count_lines_func(char **map_temp, t_game_data *game);
void	count_line_length(char **map_temp, t_game_data *game);
int		compare_lines_length(char **map_temp, t_game_data *game);
int		is_rectangle(t_game_data *game);
int		is_encircled_by_trees(char **map_temp, t_game_data *game);
void	flood_fill(t_game_data *game, int x, int y, char visited);
void	render_error(int error);
void	init(char **map, int width, int height, t_game_data *game);
int		load_images(t_game_data *game, char *img_path);
int		drawing_map(char **map, t_game_data *game);
void	change_map(char	**map, t_game_data *game, int y, int x);
void 	handle_movement(t_game_data *game, int y, int x, char *img_path);
int		redraw_map(char **map, t_game_data *game);
void 	key_hook(mlx_key_data_t keydata, void* param);
void	show_movements(t_game_data *game);
void	count_pokeballs(t_game_data *game);

#endif

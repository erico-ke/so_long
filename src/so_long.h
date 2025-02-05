/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:24:53 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/05 15:19:02 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libs/libft/src/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define UP      13
# define DOWN    1
# define LEFT    0
# define RIGHT   2
# define ESC     53
# define IMG_PXL 50

typedef struct s_player
{
	int	y;
	int	x;
}	t_player;

typedef struct s_img
{
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*tile;
}	t_img;

typedef struct s_map
{
	char		**map;
	char		**map_save;
	int			moves;
	t_img		img;
	t_player	player;
	int			exit;
	int			exit_c;
	int			coin;
	int			coin_c;
	int			player_num;
	int			player_c;
	int			map_height;
	int			map_width;
	int			null_check;
}	t_map;

int		print_error(char *ret);
int		map_control(t_map *map, char *map_input);
void	flood_fill(t_map *map, int y, int x);
void	the_freer(char	**free_me);
int		self_map_read(t_map *map);
void	map_list_init(t_map *map);
void	free_all(t_map *map);
int		main(int argc, char **argv);

#endif
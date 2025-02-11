/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:44 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/11 15:25:01 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void image_init(t_map *map)
{
	map->img.collectible = mlx_load_png("./textures/Egg_item.png");
	map->img.wall = mlx_load_png("./textures/Water.png");
	map->img.exit_c = mlx_load_png("./textures/GoldMine_Inactive.png");
	map->img.exit_o = mlx_load_png("./textures/GoldMine_Active.png");
	map->img.player = mlx_load_png("./textures/Dino.png");
	map->img.tile = mlx_load_png("./textures/floor.png");
	map->img.collect_i = mlx_texture_to_image(map->wind, map->img.collectible);
	map->img.wall_i = mlx_texture_to_image(map->wind, map->img.wall);
	map->img.exit_c_i = mlx_texture_to_image(map->wind, map->img.exit_c);
	map->img.exit_o_i = mlx_texture_to_image(map->wind, map->img.exit_o);
	map->img.player_i = mlx_texture_to_image(map->wind, map->img.player);
	map->img.tile_i = mlx_texture_to_image(map->wind, map->img.tile);
}

int	init_window(t_map *map)
{
	map->wind = mlx_init(IMG_PXL * map->map_width, IMG_PXL * map->map_height, "so_long", false);
	
	mlx_loop(map->wind);
	return (0);
}
int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (print_error("Please insert one argument, just one."));
	map = ft_calloc(1, sizeof(t_map));
	if (map_control(map, argv[1]) == EXIT_FAILURE)
	{
		free_all(map);
		return (EXIT_FAILURE);
	}
	init_window(map);
	free_all(map);
	return (EXIT_SUCCESS);
}


/* 
mlx_init para inicializar la ventana
mlx_set_window_size para inicializar con tamaño variable en caso de ser necesario
mlx_loop para que empiece el renderizado del loop(abre ventana)
mlx_close_window para cerrar la ventana
mlx_terminate limpia todo lo de la ventana
mlx_set_icon, le da un icono a la ventana en la barra de apps(abajo)
mlx_is_key_down, checkea si una key esta apretada
mlx_load_xpm42 carga de texturas en formato xpm42
mlx_delete_xpm42 libera la data de la textura, destruyendola
 */
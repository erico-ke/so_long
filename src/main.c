/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:44 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/07 18:10:02 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
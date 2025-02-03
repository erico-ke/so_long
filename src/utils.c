/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:22:04 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/03 18:22:17 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	self_map_read(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (map->map[i][0] != '1')
		return (print_error("Invalid map, border not closed."));
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->coin += 1;
			if (map->map[i][j] == 'P')
				{
					map->player.y = i;
					map->player.x = j;
				}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}//NO OLVIDAR CHECKEO DE QUE x E y TENGAN UN VALOR ASIGNADO CUANDO SE TERMINE LA FUNCION

static void	set_map_dimensions(t_map *map)
{
	int i;
	int	j;
	int j_first;

	i = 0;
	j = ft_strlen(map->map[0]);
	j_first = 0;
	while (map->map[i++] != NULL)
	{
		if (j_first == 0 || j == j_first)	
			j_first = j;
		else
			map->null_check += 1;
	}
	map->map_height = i - 1;
	map->map_width = j;
}

void	map_list_init(t_map *map)
{

	map->exit = 0;
	map->moves = 0;
	map->coin = 0;
	map->coin_c = 0;
	map->null_check = 0;
	set_map_dimensions(map);
}

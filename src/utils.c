/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:22:04 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/30 15:53:42 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strdupper(char **src, char **dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			while (i-- >= 0)
				free(dest[i]);
			return(print_error("Map copying error."));
		}
		i++;
	}
	dest[i] = ft_calloc(1, sizeof(char *));
	return (EXIT_SUCCESS);
}

void	self_map_read(t_map map)
{
	int	i;
	int	j;

	i = 0;
	if (map.map[i][0] != '1')
		return (print_error("Invalid map, border not closed."));
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				map.coin += 1;
			if (map.map[i][j] == 'P')
				{
					map.player.y = i;
					map.player.x = j;
				}
			j++;
		}
		i++;
	}
}//NO OLVIDAR CHECKEO DE QUE x E y TENGAN UN VALOR ASIGNADO CUANDO SE TERMINE LA FUNCION

void	map_list_init(t_map map)
{
	map.exit = 0;
	map.moves = 0;
	map.coin = 0;
	map.coin_c = 0;
	map.null_check = 0;
	set_map_dimensions(map);
}

void	set_map_dimensions(t_map map)
{
	int	i;
	int	j;
	int i_first;
	int j_first;

	i = 0;
	while (map.map[i++])
	{
		j = ft_strlen(map.map[i]);
		if (j_first == 0 || j == j_first)	
			j_first = j;
		else
			map.null_check += 1;
	}
	i = 0;
	while (map.map[i][j++])
	{
		while (map.map[i][j])
			i++;
		if (i_first == 0 || i == i_first)	
			i_first = i;
		else
			map.null_check += 1;
	}
}

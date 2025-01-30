/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:51:51 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/30 17:10:33 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Map validation functions*/

int	map_control(t_map map, char *map_input)
{
	if (is_map_ber(map_input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_map_valid(map, map_input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (strdupper(map.map, map.map_save) == EXIT_FAILURE)
		return (the_freer(map.map), EXIT_FAILURE);
	
}
//y lo demas que conlleve la revision del mapa
//Aca va flood_fill y revision propia al mapa, hay que hacer que el t_map tenga su ancho y largo, encontrar la poscicion x e y del jugador 

static int	is_map_ber(char *input)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(input) - 4;
	j = 0;
	str = ".ber";
	while (input[i] == str[j] && input[i])
	{
		i++;
		j++;
		if (input[i] != str[j] || input[i - j] != str[0])
			return (print_error("Incorrect map format: <map>.ber"));
	}
	return (EXIT_SUCCESS);
}

static int	is_map_valid(t_map map, char *input)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(input, O_RDONLY);
	if (fd < 0)
		return (print_error("Map open error"));
	while (map.map[i][0] != '\0' || i == 0)
	{
		map.map[i] = get_next_line(fd);
		if (!map.map[i])
		{
			while (i-- >= 0)
				free(map.map[i]);
			close(fd);
			return (print_error("Map read error."));
		}
		i++;
	}
	map.map[i][0] = '\0';
	close(fd);
	return (EXIT_SUCCESS);
}
//setear las dimensiones del mapa, NO OLVIDAR. tambien inicializar todos los demas valores de este.
void	flood_fill(t_map map, int y, int x)
{
	if (map.map_save[y][x] == '1')
		return ;
	if (map.map_save[y][x] == '*')
		return ;
	if (map.map_save[y][x] == 'P')
		map.player_num += 1;
	if (map.map_save[y][x] == 'C')
		map.coin_c += 1;
	if (map.map_save[y][x] == 'E')
		map.exit += 1;
	if (y == 0 || x == 0 || y == map.map_height || x == map.map_width)
	{
		map.null_check += 1;
		return ;
	}
	map.map_save[y][x] = '*';
	flood_fill(map, y + 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x - 1);
}

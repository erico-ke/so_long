/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:51:51 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/29 18:10:55 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_ber(char *input)
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

int	is_map_valid(t_map map, char *input)
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
//Hay que eliminar el \n de cada linea

// Si encuentra un nulo contador nulos ++ y dsp error por mapa invalido, si no saco los saltos de linea lo mismo con eso
// Quizas tengo que hacer que la ultima linea de **map sea [null,null,null,null] cantidad de nulos que haya segun la cantidad de columnas en el array de map
//si en la esquina de arriba a la derecha hay [0, 0, 1...etc] esos dos 0 pueden dar un error, hacer un chackeo de que no haya 0 en la esquina, tiene que ser 1 si o si
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
	if (map.map_save[y][x] == '\0') // cambiar para que sea segun el tamaño del mapa, lo hace mas facil, si y o x == 0 o si y o x == map.size.(y||x) o la variable que sea
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
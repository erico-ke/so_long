/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:44 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/23 14:29:25 by erico-ke         ###   ########.fr       */
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
			return (print_error("Invalid map type, it has to be terminated in .ber."));
	}
	return (EXIT_SUCCESS);
}

int	print_error(char *ret)
{
	ft_printf("%s\n", ret);
	return (EXIT_FAILURE);
}

int	is_map_valid(t_map map, char *input)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(input, O_RDONLY);
	while (map.map[i][0] != '\0' || i == 0)
	{
		map.map[i] = get_next_line(fd);
		if (!map.map[i])
		{
			while (i-- >= 0)
				free(map.map[i]);
			return (print_error("Map read error."));
		}
		i++;
	}
	map.map[i][0] = '\0';
	return (flood_fill());
}

int	flood_fill()
{
	
}

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc != 2)
		ft_printf("Please insert one argument, just one.\n");
	else
		{
			
		}
	return (0);
}
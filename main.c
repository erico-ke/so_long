/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:44 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/22 12:54:34 by erico-ke         ###   ########.fr       */
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

	fd = open(input, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		print_error("Map read error.");
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
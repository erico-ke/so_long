/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:19:44 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/03 19:15:01 by erico-ke         ###   ########.fr       */
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

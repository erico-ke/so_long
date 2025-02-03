/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:55:14 by erico-ke          #+#    #+#             */
/*   Updated: 2025/02/03 18:27:12 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *ret)
{
	ft_printf("%s\n", 2, ret);
	return (EXIT_FAILURE);
}

void	the_freer(char	**free_me)
{
	int	i;

	i = 0;
	while (free_me[i])
	{
		free(free_me[i]);
		i++;
	}
	free(free_me);
}

void	free_all(t_map *map)
{
	
	the_freer(map->map);
	the_freer(map->map_save);
	free(map);
}

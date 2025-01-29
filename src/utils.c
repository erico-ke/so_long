/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:22:04 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/29 19:22:35 by erico-ke         ###   ########.fr       */
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

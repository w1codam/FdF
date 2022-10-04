/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 11:59:11 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/07 12:21:41 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_map *map)
{
	int	index;

	index = 0;
	if (map->map)
	{
		while (map->map[index] && index < map->dimensions.y)
		{
			free(map->map[index]);
			index++;
		}
		free(map->map);
	}
	index = 0;
	if (map->colors)
	{
		while (map->colors[index] && index < map->dimensions.y)
		{
			free(map->colors[index]);
			index++;
		}
		free(map->colors);
	}
}

void	clean(t_data *data)
{
	free_map(&data->map);
}

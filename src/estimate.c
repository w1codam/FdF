/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   estimate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:28:41 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/07 12:15:25 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_dimension(t_data *data)
{
	if (data->mlx.window_size.x > 2496 || data->mlx.window_size.y > 1404)
	{
		data->view.scale_xy--;
		return (1);
	}
	else if (data->mlx.window_size.x < 1200 || data->mlx.window_size.y < 800)
	{
		data->view.scale_xy++;
		return (1);
	}
	return (0);
}

void	estimate_delta(t_data *data, int padding)
{
	t_point	p1;
	t_point	p2;

	while (1)
	{
		coord_to_screen(data, 0, data->map.dimensions.y - 1, &p1);
		coord_to_screen(data, data->map.dimensions.x - 1, 0, &p2);
		data->mlx.window_size.x = abs(p1.x - p2.x) + padding * 2;
		coord_to_screen(data, 0, 0, &p1);
		coord_to_screen(data, data->map.dimensions.x - 1, \
			data->map.dimensions.y - 1, &p2);
		data->mlx.window_size.y = abs(p1.y - p2.y) + padding * 2;
		if (check_dimension(data))
			continue ;
		coord_to_screen(data, 0, 0, &p1);
		coord_to_screen(data, 0, data->map.dimensions.y - 1, &p2);
		data->view.model_offset.x = abs(p2.x - p1.x) + padding;
		data->view.model_offset.y = padding;
		data->view.scale_z = data->view.scale_xy / 10;
		if (!data->view.scale_z)
			data->view.scale_z = 1;
		break ;
	}
}

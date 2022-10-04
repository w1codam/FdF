/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 14:31:24 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/02 11:54:54 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_to_screen(t_data *data, int x, int y, t_point *coord)
{
	coord->x = (x - y) * cos(data->view.rot) * data->view.scale_xy;
	coord->y = (-data->map.map[y][x] * data->view.scale_z) + (x + y) \
		* sin(data->view.rot) * data->view.scale_xy;
	coord->x += data->view.model_offset.x;
	coord->y += data->view.model_offset.y;
}

void	render_x(t_data *data, int y)
{
	int		index;
	t_point	p1;
	t_point	p2;

	index = 0;
	while (index < data->map.dimensions.x - 1)
	{
		coord_to_screen(data, index, y, &p1);
		coord_to_screen(data, index + 1, y, &p2);
		draw_line(data, p1, p2);
		index++;
	}
}

void	render_y(t_data *data, int x)
{
	int		index;
	t_point	p1;
	t_point	p2;

	index = 0;
	while (index < data->map.dimensions.y - 1)
	{
		coord_to_screen(data, x, index, &p1);
		coord_to_screen(data, x, index + 1, &p2);
		draw_line(data, p1, p2);
		index++;
	}
}

void	render_map(t_data *data)
{
	int	index;

	draw_background(data, 0x00222222);
	index = 0;
	while (index < data->map.dimensions.y)
	{
		render_x(data, index);
		index += 1;
	}
	index = 0;
	while (index < data->map.dimensions.x)
	{
		render_y(data, index);
		index += 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:39:42 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/08 10:54:08 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_in(t_data *data)
{
	t_point	y1;
	t_point	y2;
	int		diff[2];

	coord_to_screen(data, 0, 0, &y1);
	coord_to_screen(data, data->map.dimensions.x - 1, \
		data->map.dimensions.y - 1, &y2);
	diff[0] = abs(y1.x - y2.x);
	diff[1] = abs(y1.y - y2.y);
	data->view.scale_xy += 1;
	coord_to_screen(data, 0, 0, &y1);
	coord_to_screen(data, data->map.dimensions.x - 1, \
		data->map.dimensions.y - 1, &y2);
	diff[0] = abs(y1.x - y2.x) - diff[0];
	diff[1] = abs(y1.y - y2.y) - diff[1];
	data->view.model_offset.x -= diff[0] / 2;
	data->view.model_offset.y -= diff[1] / 2;
}

static void	zoom_out(t_data *data)
{
	t_point	y1;
	t_point	y2;
	int		diff[2];

	if (data->view.scale_xy == 1)
		return ;
	coord_to_screen(data, 0, 0, &y1);
	coord_to_screen(data, data->map.dimensions.x - 1, \
		data->map.dimensions.y - 1, &y2);
	diff[0] = abs(y1.x - y2.x);
	diff[1] = abs(y1.y - y2.y);
	data->view.scale_xy -= 1;
	coord_to_screen(data, 0, 0, &y1);
	coord_to_screen(data, data->map.dimensions.x - 1, \
		data->map.dimensions.y - 1, &y2);
	diff[0] = diff[0] - abs(y1.x - y2.x);
	diff[1] = diff[1] - abs(y1.y - y2.y);
	data->view.model_offset.x += diff[0] / 2;
	data->view.model_offset.y += diff[1] / 2;
}

int	close_hook(t_data *data)
{
	clean(data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 31)
		data->view.scale_z += 1;
	else if (keycode == 35)
		data->view.scale_z -= 1;
	else if (keycode == 40)
		zoom_in(data);
	else if (keycode == 37)
		zoom_out(data);
	else if (keycode == 123)
		data->view.model_offset.x -= 5;
	else if (keycode == 124)
		data->view.model_offset.x += 5;
	else if (keycode == 126)
		data->view.model_offset.y -= 5;
	else if (keycode == 125)
		data->view.model_offset.y += 5;
	else if (keycode == 53)
	{
		clean(data);
		exit(1);
	}
	render_map(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.window, \
		data->mlx.img, 0, 0);
	return (0);
}

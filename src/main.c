/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 12:32:34 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/07 12:09:15 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int args, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (args != 2)
		error(&data, "usage: ./fdf <map>");
	data.view.rot = 0.523599;
	data.view.scale_xy = 10;
	data.view.scale_z = 1;
	if (!parse_map(&data, argv[1]))
		error(&data, "failed to parse map: x<1 || y<1 or map does not exist");
	estimate_delta(&data, 25);
	data.mlx.mlx = mlx_init();
	data.mlx.window = mlx_new_window(data.mlx.mlx, data.mlx.window_size.x, \
		data.mlx.window_size.y, "fdf");
	data.mlx.img = mlx_new_image(data.mlx.mlx, data.mlx.window_size.x, \
		data.mlx.window_size.y);
	data.mlx.pixels = mlx_get_data_addr(data.mlx.img, &data.mlx.bits_per_pixel, \
		&data.mlx.size_line, &data.mlx.endian);
	render_map(&data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.window, data.mlx.img, 0, 0);
	mlx_hook(data.mlx.window, 0x11, 0, close_hook, &data);
	mlx_hook(data.mlx.window, 0x02, 0, key_hook, &data);
	mlx_loop(data.mlx.mlx);
}

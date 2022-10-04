/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 15:07:14 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/02 12:27:56 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_setup(t_point a, t_point b, int *delta, int *incr)
{
	delta[0] = abs(a.x - b.x);
	delta[1] = abs(a.y - b.y);
	incr[0] = -1;
	incr[1] = -1;
	if (b.x < a.x)
		incr[0] = 1;
	if (b.y < a.y)
		incr[1] = 1;
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= data->mlx.window_size.x || y >= data->mlx.window_size.y)
		return ;
	if (x < 0 || y < 0)
		return ;
	dst = data->mlx.pixels + ((y * data->mlx.size_line) + x * 4);
	*(unsigned int *)dst = color;
}

void	draw_background(t_data *data, int color)
{
	int	index;

	index = 0;
	while (index < data->mlx.window_size.x * data->mlx.window_size.y)
	{
		put_pixel(data, index % data->mlx.window_size.x, \
			index / data->mlx.window_size.x, color);
		index++;
	}
}

void	draw_line(t_data *data, t_point a, t_point b)
{
	int	delta[2];
	int	incr[2];
	int	cur[2];
	int	error;

	ft_setup(a, b, delta, incr);
	error = 2 * (delta[1] - delta[0]);
	cur[0] = b.x;
	cur[1] = b.y;
	while (1)
	{
		put_pixel(data, cur[0], cur[1], 0x00444444);
		if (cur[0] == a.x && cur[1] <= a.y)
			break ;
		if (error >= 0)
		{
			cur[1] += incr[1];
			error -= 2 * delta[0];
		}
		if (error < 0)
		{
			cur[0] += incr[0];
			error += 2 * delta[1];
		}
	}
}

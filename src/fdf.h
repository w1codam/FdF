/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 16:18:28 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/08 10:53:41 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stddef.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_point {
	int		x;
	int		y;
	int		color;
}			t_point;

typedef struct s_mlx {
	t_point	window_size;
	void	*mlx;
	void	*window;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	*img;
	char	*pixels;
}			t_mlx;

typedef struct s_map {
	t_point	dimensions;
	int		**map;
	int		**colors;
}			t_map;

typedef struct s_view {
	int		scale_xy;
	int		scale_z;
	t_point	model_offset;
	float	rot;
}			t_view;

typedef struct s_data {
	t_mlx	mlx;
	t_map	map;
	t_view	view;
}			t_data;

// draw functions
void	put_pixel(t_data *data, int x, int y, int color);
void	draw_background(t_data *data, int color);
void	draw_line(t_data *data, t_point a, t_point b);
void	render_map(t_data *data);

// map functions
int		parse_map(t_data *data, const char *path);
void	estimate_window_size(t_data *data);
void	estimate_scale(t_data *data);

// mlx functions
void	create_window(t_data *data);

// error
void	error(t_data *data, const char *err);

// estimate
void	estimate_delta(t_data *data, int padding);

// render
void	coord_to_screen(t_data *img, int x, int y, t_point *coord);
void	render_x(t_data *data, int y);
void	render_y(t_data *data, int y);
void	render_map(t_data *data);

// hooks
int		close_hook(t_data *data);
int		key_hook(int keycode, t_data *data);

// cleanup
void	clean(t_data *data);

#endif

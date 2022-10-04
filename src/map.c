/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 13:01:43 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/02/28 18:27:52 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *line)
{
	int		width;
	int		index;

	width = 0;
	index = 0;
	while (line[index])
	{
		while (line[index] && line[index] == ' ')
			index++;
		if (ft_isdigit(line[index]) || line[index] == '-')
			width++;
		while (line[index] && line[index] != ' ')
		{
			if (line[index] == '\n')
				break ;
			index++;
		}
		index++;
	}
	return (width);
}

static void	get_map_size(t_point *dimensions, const char *path)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	dimensions->x = get_width(line);
	while (line)
	{
		if (dimensions->x == get_width(line))
			dimensions->y += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static int	load_line(t_data *data, int y, int fd)
{
	int		index;
	char	*line;
	char	**split;

	index = 0;
	data->map.map[y] = (int *)calloc(data->map.dimensions.x, sizeof(int));
	if (!data->map.map[y])
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	split = ft_split(line, ' ');
	free(line);
	while (split[index])
	{
		if (index < data->map.dimensions.x)
			data->map.map[y][index] = ft_atoi(split[index]);
		free(split[index]);
		index++;
	}
	free(split);
	return (1);
}

static int	parse(t_data *data, const char *path)
{
	int		index;
	int		fd;
	int		ret;

	index = 0;
	ret = 1;
	data->map.map = calloc(data->map.dimensions.y, sizeof(int *));
	if (!data->map.map)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (index < data->map.dimensions.y)
	{
		ret = load_line(data, index, fd);
		if (!ret)
			break ;
		index++;
	}
	close(fd);
	return (ret);
}

int	parse_map(t_data *data, const char *path)
{
	get_map_size(&data->map.dimensions, path);
	if (data->map.dimensions.x == 0 || data->map.dimensions.y == 0)
		return (0);
	if (!parse(data, path))
		return (0);
	return (1);
}

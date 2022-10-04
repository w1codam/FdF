/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:50:50 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/02/14 10:30:27 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*p1(char **result, char **remainder)
{
	(*result) = m_realloc((*result), (*remainder), \
		get_char_index((*remainder), '\n') + 1);
	if (!(*result))
		return (NULL);
	(*remainder) = shift_buffer((*remainder), \
		get_char_index((*remainder), '\n') + 1);
	if (!(*remainder))
		return (NULL);
	if ((*result)[0] == 0)
	{
		free(result);
		return (NULL);
	}
	return ((*result));
}

static char	*p2(char **result, char **remainder, int b_read)
{
	if (b_read < 0)
	{
		if ((*remainder))
		{
			free((*remainder));
			(*remainder) = NULL;
		}
		return (NULL);
	}
	if (b_read == 0)
	{
		free((*remainder));
		(*remainder) = NULL;
		if ((*result))
		{
			if ((*result)[0] == 0)
			{
				free((*result));
				return (NULL);
			}
			return ((*result));
		}
		return (NULL);
	}
	return (NULL);
}

static int	p3(char **result, char **remainder)
{
	(*result) = m_realloc((*result), (*remainder), \
		get_char_index((*remainder), '\0'));
	if (!(*result))
		return (0);
	free((*remainder));
	(*remainder) = NULL;
	return (1);
}

int	yeet(char **remainder, char **result)
{
	*remainder = malloc(BUFFER_SIZE + 1);
	if (!*remainder)
	{
		free(*result);
		return (0);
	}
	ft_g_memset(*remainder, 0, BUFFER_SIZE + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*result;
	int			b_read;

	result = NULL;
	if (remainder != NULL)
	{
		if (get_char_index(remainder, '\n') != -1)
			return (p1(&result, &remainder));
		if (!p3(&result, &remainder))
			return (NULL);
	}
	while (1)
	{
		if (yeet(&remainder, &result) == 0)
			return (NULL);
		b_read = read(fd, remainder, BUFFER_SIZE);
		if (b_read <= 0)
			return (p2(&result, &remainder, b_read));
		if (get_char_index(remainder, '\n') != -1)
			return (p1(&result, &remainder));
		if (!p3(&result, &remainder))
			return (NULL);
	}
	return (result);
}

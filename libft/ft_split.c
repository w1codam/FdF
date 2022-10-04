/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:36:45 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_parts(char const *s, char c)
{
	int		parts;
	int		index;

	parts = 0;
	index = 0;
	while (s[index] != '\0' && s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		while (s[index] != '\0' && s[index] != c)
			index++;
		while (s[index] != '\0' && s[index] == c)
			index++;
		parts++;
	}
	return (parts);
}

static int	ft_part_length(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] != c && s[length] != '\0')
		length++;
	return (length);
}

static void	ft_null_indexes(int *indexes, char **result, int parts)
{
	int	index;

	index = 0;
	if (indexes != NULL)
	{
		while (index < 3)
		{
			index++;
			indexes[index - 1] = 0;
		}
		while (parts > 0)
		{
			parts--;
			result[parts] = 0;
		}
		return ;
	}
	while (parts > 0)
	{
		parts--;
		if (result[parts] != 0)
			free(result[parts]);
	}
}

static int	ft_parthandler(char const *s, char **result, int *ndx, char c)
{
	while (s[ndx[2]] != '\0' && s[ndx[2]] == c)
		ndx[2]++;
	ndx[1] = 0;
	result[ndx[0]] = (char *)malloc(ft_part_length(&(s[ndx[2]]), c) + 1);
	if (result[ndx[0]] == NULL)
		return (0);
	while (s[ndx[2] + ndx[1]] != c && s[ndx[2] + ndx[1]] != '\0')
	{
		result[ndx[0]][ndx[1]] = s[ndx[2] + ndx[1]];
		ndx[1]++;
	}
	result[ndx[0]][ndx[1]] = '\0';
	ndx[2] += ndx[1];
	ndx[0]++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		ndx[3];
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_get_parts(s, c) + 1));
	if (result == NULL)
		return (NULL);
	ft_null_indexes(&(ndx[0]), result, ft_get_parts(s, c) + 1);
	while (ndx[0] < ft_get_parts(s, c))
	{
		if (!ft_parthandler(s, result, ndx, c))
		{
			ft_null_indexes(NULL, result, ft_get_parts(s, c));
			free(result);
			return (NULL);
		}
	}
	return (result);
}

// char	**ft_split(char const *s, char c)
// {
// 	int		a_index;
// 	int		s_index;
// 	int		w_index;
// 	char	**result;

// 	result = (char **)malloc(sizeof(char *) * (ft_get_parts(s, c) + 1));
// 	if (result == NULL)
// 		return (NULL);
// 	result[ft_get_parts(s, c)] = NULL;
// 	a_index = 0;
// 	s_index = 0;
// 	while (a_index < ft_get_parts(s, c))
// 	{
// 		while (s[s_index] != '\0' && s[s_index] == c)
// 			s_index++;
// 		w_index = 0;
// 		result[a_index] = (char *)malloc(ft_part_length(&(s[s_index]), c) + 1);
// 		while (s[s_index + w_index] != c && s[s_index + w_index] != '\0')
// 		{
// 			result[a_index][w_index] = s[s_index + w_index];
// 			w_index++;
// 		}
// 		result[a_index][w_index] = '\0';
// 		s_index += w_index;
// 		a_index++;
// 	}
// 	return (result);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:37:12 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(int c, char const *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	ft_trimmedlen(char const *s1, char const *set)
{
	int	index;
	int	length;

	length = 0;
	while (s1[length] != '\0')
		length++;
	index = 0;
	while (length - index > 0 && ft_is_in_set(s1[length - index - 1], set))
		index++;
	length -= index;
	index = 0;
	while (s1[index] != '\0' && ft_is_in_set(s1[index], set))
	{
		length--;
		index++;
	}
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trimmed_length;
	int		index;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	trimmed_length = ft_trimmedlen(s1, set);
	if (trimmed_length <= 0)
		return (ft_strdup(""));
	result = (char *)malloc(trimmed_length + 1);
	if (result == NULL)
		return (NULL);
	result[trimmed_length] = '\0';
	index = 0;
	while (ft_is_in_set(s1[index], set))
		index++;
	while (trimmed_length > 0)
	{
		trimmed_length--;
		result[trimmed_length] = s1[trimmed_length + index];
	}
	return (result);
}

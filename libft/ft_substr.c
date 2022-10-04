/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:37:14 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			index;
	unsigned int	length;
	char			*result;

	if (!s)
		return (NULL);
	length = 0;
	while (s[length] != '\0')
		length++;
	if (length < start)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < len && s[start + index] != '\0')
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

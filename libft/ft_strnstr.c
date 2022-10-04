/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:37:07 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	inner_index;

	index = 0;
	if (!*needle)
		return ((char *)haystack);
	while (index < len && haystack[index] != '\0')
	{
		inner_index = 0;
		while (haystack[index + inner_index] == needle[inner_index] && \
				needle[inner_index] != '\0' && len > index + inner_index)
			inner_index++;
		if (needle[inner_index] == '\0')
			return ((char *)(&haystack[index]));
		index++;
	}
	return (NULL);
}

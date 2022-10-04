/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:36:49 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		length;

	length = 0;
	while (s1[length] != '\0')
		length++;
	ptr = malloc(length * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	length = 0;
	while (s1[length] != '\0')
	{
		ptr[length] = s1[length];
		length++;
	}
	ptr[length] = '\0';
	return (ptr);
}

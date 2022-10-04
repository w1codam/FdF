/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:37:05 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	index;

	index = 0;
	if (s1 == s2)
		return (0);
	while (((unsigned char)(s1[index]) != '\0' || \
		(unsigned char)(s2[index]) != '\0') && n > 0)
	{
		n--;
		if (s1[index] != s2[index])
			return ((unsigned char)(s1[index]) - \
				(unsigned char)(s2[index]));
		index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:36:54 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_l;
	unsigned int	s2_l;
	char			*result;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	result = (char *)malloc(s1_l + s2_l + 1);
	if (result == NULL)
		return (NULL);
	result[s1_l + s2_l] = '\0';
	while (s2_l > 0)
	{
		s2_l--;
		result[s1_l + s2_l] = s2[s2_l];
	}
	while (s1_l > 0)
	{
		s1_l--;
		result[s1_l] = s1[s1_l];
	}
	return (result);
}

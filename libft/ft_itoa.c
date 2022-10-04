/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:35:49 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	length;

	length = 0;
	if (n < 0)
		length++;
	if (n == 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int	ft_get_cur_val(int n)
{
	int	curval;

	curval = (n % 10);
	if (curval < 0)
		curval *= -1;
	return (curval);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		index;

	res = malloc(ft_ilen(n) + 1);
	if (res == NULL)
		return (NULL);
	res[ft_ilen(n)] = 0;
	index = ft_ilen(n) - 1;
	if (n < 0)
		res[0] = '-';
	while (n > 9 || n < -9)
	{
		res[index] = '0' + ft_get_cur_val(n);
		n /= 10;
		index--;
	}
	res[index] = '0' + ft_get_cur_val(n);
	return (res);
}

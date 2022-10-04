/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:36:40 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_revprint(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		len--;
		ft_putchar_fd(s[len], fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[11];
	int		index;

	index = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	while (n > 9)
	{
		nbr[index] = '0' + (n % 10);
		n /= 10;
		index++;
	}
	nbr[index] = '0' + n;
	nbr[index + 1] = 0;
	ft_revprint(nbr, fd);
}

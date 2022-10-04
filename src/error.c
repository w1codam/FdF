/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 12:07:04 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/07 12:18:33 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(t_data *data, const char *err)
{
	clean(data);
	ft_putstr_fd("error: ", STDERR_FILENO);
	ft_putstr_fd((char *)err, STDERR_FILENO);
	exit(1);
}

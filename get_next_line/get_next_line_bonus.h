/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:50:41 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/02/01 14:31:19 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define BUFFER_SIZE 1024

char	*get_next_line(int fd);

int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*m_realloc(void *base, void *end, int length);
int		get_char_index(char *str, char c);
void	*shift_buffer(void *buffer, int start);

#endif
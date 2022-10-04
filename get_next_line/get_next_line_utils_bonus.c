/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:50:45 by jde-groo      #+#    #+#                 */
/*   Updated: 2021/12/13 12:50:45 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	get_char_index(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	if (c == 0)
		return (index);
	return (-1);
}

char	*m_realloc(void *base, void *end, int length)
{
	char	*res;
	int		base_len;

	base_len = 0;
	if (base)
		while (((unsigned char *)base)[base_len] != '\0')
			base_len++;
	res = malloc(base_len + length + 1);
	if (res == NULL)
		return (NULL);
	res[base_len + length] = '\0';
	while (length > 0)
	{
		length--;
		*((unsigned char *)res + base_len + length) = \
			*((unsigned char *)end + length);
	}
	while (base_len > 0)
	{
		base_len--;
		*((unsigned char *)res + base_len) = \
			*((unsigned char *)base + base_len);
	}
	free(base);
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		*((unsigned char *) b + len) = (unsigned char)c;
	}
	return (b);
}

void	*shift_buffer(void *buffer, int start)
{
	int		index;
	int		buffer_length;
	char	*result;

	buffer_length = ft_strlen(buffer);
	result = malloc(buffer_length - start + 1);
	if (!result)
		return (NULL);
	result[buffer_length - start] = 0;
	index = 0;
	while (buffer_length - start > index)
	{
		result[index] = ((char *)(buffer))[start + index];
		index++;
	}
	free(buffer);
	return (result);
}

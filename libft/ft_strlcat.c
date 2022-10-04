/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 15:36:56 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/03/18 15:37:31 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (!n || dstlen >= n)
		return (ft_strlen(src) + n);
	while (src[i] != '\0' && i < n - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (ft_strlen(src) + dstlen);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	src_len;
// 	size_t	dst_len;

// 	src_len = ft_strlen(src);
// 	dst_len = ft_strlen(dst);
// 	if (!dstsize || dst_len >= dstsize)
// 		return (src_len + dstsize);
// 	ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
// 	dst[dstsize - 1] = '\0';
// 	return (src_len + dst_len);
// }

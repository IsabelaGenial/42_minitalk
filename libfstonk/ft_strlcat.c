/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:29:23 by igenial           #+#    #+#             */
/*   Updated: 2023/05/22 13:31:54 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = (ft_strlen(dst));
	src_len = (ft_strlen(src));
	i = 0;
	if (dst_len >= size)
		return (size + src_len);
	while ((dst_len + i) < (size - 1) && src[i])
	{
		dst[dst_len + i] = ((char *)src)[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

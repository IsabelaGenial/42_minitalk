/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:01:32 by igenial           #+#    #+#             */
/*   Updated: 2023/09/18 16:43:53 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{	
	char	*s;

	s = ((char *)src);
	if (size == 0)
		return (ft_strlen(src));
	while ((size - 1) && *s)
	{
		*dst++ = *s++;
		size--;
	}
	*dst = '\0';
	return (ft_strlen(src));
}

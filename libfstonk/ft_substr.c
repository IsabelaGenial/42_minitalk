/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:57:42 by igenial           #+#    #+#             */
/*   Updated: 2023/05/28 15:31:43 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*strmalloc;
	size_t	i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		start = slen;
		len = 0;
	}
	if (start + len > slen)
		len = slen - start;
	strmalloc = ft_calloc(len + 1, sizeof(char));
	if (!strmalloc)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		strmalloc[i] = s[start];
		i++;
		start++;
	}
	return (strmalloc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:11:37 by igenial           #+#    #+#             */
/*   Updated: 2023/06/01 17:36:15 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*strmalloc;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_calloc(1, sizeof(char)));
	len = (ft_strlen(s1));
	while (ft_strrchr(set, s1[len]))
		len--;
	strmalloc = ft_calloc(len + 2, sizeof(char));
	if (!strmalloc)
		return (NULL);
	ft_strlcpy(strmalloc, s1, len + 2);
	return (strmalloc);
}

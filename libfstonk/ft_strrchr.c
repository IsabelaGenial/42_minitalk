/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:22:18 by igenial           #+#    #+#             */
/*   Updated: 2023/05/27 18:42:13 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (ft_strlen(s));
	while (i > -1)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if ((unsigned char)c == 0)
		return ((char *)s + i);
	return (NULL);
}

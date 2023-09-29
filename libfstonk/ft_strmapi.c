/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:29 by igenial           #+#    #+#             */
/*   Updated: 2023/05/27 21:22:40 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmalloc;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	strmalloc = malloc ((len + 1) * sizeof(char));
	if (!strmalloc)
		return (NULL);
	while (i < len)
	{
		strmalloc[i] = f(i, s[i]);
		i++;
	}
	strmalloc[i] = '\0';
	return (strmalloc);
}

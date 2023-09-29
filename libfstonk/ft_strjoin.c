/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:48:55 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 04:52:21 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*str;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = ft_calloc(lens1 + lens2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lens1 + lens2 + 1);
	return (str);
}

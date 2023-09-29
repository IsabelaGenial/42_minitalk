/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:53:02 by igenial           #+#    #+#             */
/*   Updated: 2023/06/07 20:07:48 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_littlestr(char const *s, char c);
static int		ft_biglen( char const *s, char c);
static int		ft_littlelen(char const *s, char c, size_t a);
static void		ft_insertstr(char **big, char *s, char c, size_t biglen);

char	**ft_split(char const *s, char c)
{
	char	**big;
	size_t	biglen;

	if (s == NULL)
		return (NULL);
	biglen = ft_biglen(s, c);
	big = (char **)ft_calloc((biglen + 1), sizeof(char *));
	if (!big)
		return (NULL);
	ft_insertstr(big, (char *)s, c, biglen);
	return (big);
}

static void	ft_insertstr(char **big, char *s, char c, size_t biglen)
{	
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (j < biglen)
	{	
		while (s[i] == c && s[i])
			i++;
		big[j++] = ft_littlestr(&s[i], c);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
}

static char	*ft_littlestr(char const *s, char c)
{
	char	*strmalloc;
	size_t	i;

	i = 0;
	strmalloc = ft_calloc((ft_littlelen(s, c, i) + 1), sizeof(char));
	if (!strmalloc)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		strmalloc[i] = s[i];
			i++;
	}
	return (strmalloc);
}

static int	ft_biglen(char const *s, char c)
{
	size_t	i;
	size_t	little;

	i = 0;
	little = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			little++;
		i++;
	}
	return (little);
}

static int	ft_littlelen(char const *s, char c, size_t a)
{
	size_t	little;
	size_t	i;

	little = 0;
	i = a;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		little++;
	}
	return (little);
}

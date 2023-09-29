/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:20:57 by igenial           #+#    #+#             */
/*   Updated: 2023/05/28 21:05:20 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	ft_convert(char *dst, long int n, int size);
static int	ft_intlen(long int n);

char	*ft_itoa(int n)
{
	long int	ln;
	char		*buffer;
	int			count;

	ln = n;
	count = ft_intlen(ln);
	buffer = ft_calloc((count + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	ft_convert(buffer, ln, count);
	return (buffer);
}

static int	ft_intlen(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	ft_convert(char *dst, long int n, int size)
{
	int	i;

	i = (size - 1);
	if (n < 0)
	{
		n *= -1;
		dst[0] = '-';
	}
	if (n == 0)
		dst[i] = '0';
	while (n > 0)
	{	
		dst[i] = (n % 10) + '0';
		n = (n / 10);
		i--;
	}
	return (*dst);
}

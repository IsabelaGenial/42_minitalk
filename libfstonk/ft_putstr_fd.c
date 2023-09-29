/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:26:36 by igenial           #+#    #+#             */
/*   Updated: 2023/05/26 16:00:10 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (*s)
	{
		write(fd, s, 1);
		s++;
		counter++;
	}
	return (counter);
}

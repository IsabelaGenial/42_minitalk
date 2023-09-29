/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Isabela Genial <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:07:10 by Isabela Gen       #+#    #+#             */
/*   Updated: 2023/05/26 16:58:17 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long nb, int fd)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb *= -1;
		counter += ft_putchar_fd('-', fd);
	}
	if (nb / 10 > 0)
		counter += ft_putnbr_fd(nb / 10, fd);
	nb = nb % 10 + '0';
	counter += ft_putchar_fd(nb, fd);
	return (counter);
}

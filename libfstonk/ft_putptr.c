/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:27:21 by igenial           #+#    #+#             */
/*   Updated: 2023/07/13 14:48:30 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pointer(size_t nb, char x);

int	ft_putptr(unsigned long nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (write(1, "(nil)", 5));
	counter += write(1, "0x", 2);
	counter += ft_pointer(nb, 'x');
	return (counter);
}

static int	ft_pointer(size_t nb, char x)
{
	int	counter;

	counter = 0;
	if (nb / 16 > 0)
		counter += ft_pointer(nb / 16, x);
	nb = nb % 16;
	counter += ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:49:05 by igenial           #+#    #+#             */
/*   Updated: 2023/07/13 14:44:26 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int nb, char x)
{
	int	counter;

	counter = 0;
	if (nb / 16 > 0)
		counter += ft_puthex(nb / 16, x);
	nb %= 16;
	if (x == 'x')
		counter += ft_putchar_fd("0123456789abcdef"[nb % 16], 1);
	else
		counter += ft_putchar_fd("0123456789ABCDEF"[nb % 16], 1);
	return (counter);
}

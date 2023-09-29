/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:56:51 by igenial           #+#    #+#             */
/*   Updated: 2023/09/16 04:49:44 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(const char *print, va_list action_object);

int	ft_printf(const char *print, ...)
{
	va_list	action_object;
	int		counter;

	counter = 0;
	va_start(action_object, print);
	while (*print)
	{	
		if (*print == '%')
			counter += ft_type(print++, action_object);
		else
			counter += ft_putchar_fd(*print, 1);
		print++;
	}
	va_end (action_object);
	return (counter);
}

static int	ft_type(const char *print, va_list action_object)
{
	int	counter;

	counter = 0;
	print++;
	if (*print == '%')
		counter += ft_putchar_fd('%', 1);
	if (*print == 'c')
		counter += ft_putchar_fd(va_arg(action_object, int), 1);
	if (*print == 's')
		counter += ft_putstr_fd(va_arg (action_object, char *), 1);
	if (*print == 'p')
		counter += ft_putptr(va_arg(action_object, unsigned long));
	if (*print == 'd' || *print == 'i')
		counter += ft_putnbr_fd(va_arg(action_object, int), 1);
	if (*print == 'u')
		counter += ft_putnbr_fd(va_arg(action_object, unsigned int), 1);
	if (*print == 'x' || *print == 'X')
		counter += ft_puthex(va_arg(action_object, unsigned int), *print);
	return (counter);
}

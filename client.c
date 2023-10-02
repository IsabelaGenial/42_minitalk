/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:23:05 by igenial           #+#    #+#             */
/*   Updated: 2023/10/02 11:23:07 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int argument_handling(char *number);

int main (int argc, char **argv)
{
	int num;
	const char *message = "Hello world";
	size_t message_len = ft_strlen(message);
	size_t i;

	if (argc != 2)
		ft_printf("ERROR: argument number");
	num = ft_atoi(argv[1]);
	i = 0;
	while (i < message_len)
	{
		if (kill(num, SIGUSR1 + message[i]) != 0)
			ft_printf("signal not sent");
		i++;
		usleep(100000);
	}
	return (0);
}
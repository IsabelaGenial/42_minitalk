/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:58:26 by igenial           #+#    #+#             */
/*   Updated: 2023/10/01 19:25:06 by isabela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"


void handle_signal (int signal)
{
	ft_printf("%d", signal);
}

int main ()
{
	int			pid;

	pid = getpid();
	signal(SIGUSR1, handle_signal);
	ft_printf("pid %i\n", pid);
	while (1)
		pause();
	return (0);
}

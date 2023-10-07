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

void handler(int signum, siginfo_t *info, void *context);

int main (void)
{
	int					pid;
	struct sigaction	s_sig;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sig.sa_handler = NULL;
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_mask = sigset;
	s_sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	pid = getpid();
	ft_printf("pid %i\n", pid);
	while (369)
		pause();
}

void handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0x0;
	static int				bit = 0;
	int						pid;

	(void)context;
	if(info->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
			c |= 0x1;
	if (++bit == 8)
	{
		write(1, &c, 1);
		c = 0x0;
		bit = 0;
	}
	c <<= 0x1;
//	if (signum == SIGUSR1)
//		kill(info->si_pid, SIGUSR1);
//	else
//		kill(info->si_pid, SIGUSR2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:23:05 by igenial           #+#    #+#             */
/*   Updated: 2023/10/10 00:31:25 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	g_signal;

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	s_sig;
	sigset_t			sigset;

	if (argc != 3 || !ft_str_isdigit(argv[1]))
	{
		ft_printf ("ERROR: argument number");
		exit (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sig.sa_handler = NULL;
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_mask = sigset;
	s_sig.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	ft_send_bit(pid, argv[2]);
	g_signal = 0;
}

int	ft_send_bit(int pid, char *str)
{
	char		message;
	static int	bit;

	while (*str)
	{
		message = *str;
		ft_send_bit_aux(pid, bit, message);
		str++;
	}
	return (0);
}

int	ft_str_isdigit(char *c)
{
	while (*c)
	{
		if (*c >= '0' && *c <= '9')
			return (1);
		c++;
	}
	return (0);
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	int	pid;

	(void) context;
	pid = info->si_pid;
	if (signum == SIGUSR1 || signum == SIGUSR2)
		g_signal = 1;
	else
		exit(EXIT_FAILURE);
}

void	ft_send_bit_aux(int pid, int bit, char message)
{
	bit = 0;
	while (bit < 8)
	{
		g_signal = 0;
		if ((0x80 >> bit) & message)
		{
			kill(pid, SIGUSR1);
			while (!g_signal)
				;
		}
		else
		{
			kill(pid, SIGUSR2);
			while (!g_signal)
				;
		}
		bit++;
	}
}

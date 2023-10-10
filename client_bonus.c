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

int	send_bit(int pid, char *str);
static int	ft_str_isdigit(char *c);
void handler(int signum, siginfo_t *info, void *context);

int g_signal;

int	main (int argc, char **argv)
{
	int					pid;
	struct	sigaction	s_sig;
	sigset_t			sigset;

	if (argc != 3 || !ft_str_isdigit(argv[1]))
	{
		ft_printf("ERROR: argument number");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sig.sa_handler = NULL;
	s_sig.sa_flags = SA_SIGINFO;
	s_sig.sa_mask = sigset;
	s_sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	send_bit(pid, argv[2]);
}

int	send_bit(int pid, char *str)
{
	char message;
	static int bit;

	while (*str)
	{
		message = *str;
		bit = 0;
		while (bit < 8)
		{
			g_signal = 0;
			if ((0x80 >> bit) & message)
			{
				kill(pid, SIGUSR1);
				while (g_signal == 0)
					;
			}

			else
			{
				kill(pid, SIGUSR2);
				while (g_signal == 0)
					;
			}

			bit++;
		}
		str++;
	}
	return (0);
}

static int	ft_str_isdigit(char *c)
{
	while (*c)
	{
		if (*c >= '0' && *c <= '9')
			return (1);
		c++;
	}
	return (0);
}

void handler(int signum, siginfo_t *info, void *context)
{
	int pid;
	int bit;

	(void) context;
	pid = info->si_pid;
	bit = 0x0;
	if (signum == SIGUSR1)
	{
		write(1, "1", 1);
		g_signal = 1;
		bit++;
	}
	else if (signum == SIGUSR2)
	{
		write(1, "0", 1);
		g_signal = 1;
		bit++;
	}
	if (bit == 8)
	{
		write(1, " ", 1);
		bit = 0;
	}
	else
		exit(EXIT_FAILURE);
}
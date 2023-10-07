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
	s_sig.sa_flags = 0x0;
	sigemptyset(&s_sig.sa_mask);
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
			if ((0x80 >> bit) & message)
            	kill(pid, SIGUSR1);
            else
            	kill(pid, SIGUSR2);
			usleep(500);
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

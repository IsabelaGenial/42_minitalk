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

int send_bit(int pid, char *str);
void sig_handler(int signum);
int	ft_str_isdigit(char *c);

int main (int argc, char **argv) {
    int num;

    if (argc != 3 || !ft_str_isdigit(argv[1]))
    {
        ft_printf("ERROR: argument number");
        exit(EXIT_FAILURE);
    }
	num = ft_atoi(argv[1]);
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);

    if(send_bit(num, argv[2]))
        ft_printf("ERROR: signal no sent");
	while (1)
        pause();
}

int send_bit(int pid, char *str)
{
    static char *message = 0;
    static int bit = -1;

    message = ft_strdup(str);
    if (!message)
        return (1);
    while (message[++bit/8])
    {
        if (message[bit / 8] & (0x80 >> (bit % 8)))
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                free(message)
                return (1);
            }
        } else if (kill(pid, SIGUSR1) == -1)
        {
            free(message)
            return (1);
        }
    }
    free(message);
    return (0);
}

void sig_handler(int signum)
{
    int end;

    end = 0;
    if (signum == SIGUSR1)
            end = send_bit(0, 0);
    else if (signum == SIGUSR2)
    {
        ft_printf("ERROR: server ended unexpectdly.\n");
        exit(EXIT_FAILURE);
    }
    if (end)
    {
        ft_printf("CLIENT: operation sucessful.\n");
        exit(EXIT_SUCCESS);
    }

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

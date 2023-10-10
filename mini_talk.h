/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <igenial@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:24:29 by igenial           #+#    #+#             */
/*   Updated: 2023/10/10 00:24:37 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libfstonk/libft.h"

int		ft_send_bit(int pid, char *str);
int		ft_str_isdigit(char *c);
void	ft_handler(int signum, siginfo_t *info, void *context);
void	ft_send_bit_aux(int pid, int bit, char message);
#endif

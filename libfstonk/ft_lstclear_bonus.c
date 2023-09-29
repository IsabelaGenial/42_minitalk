/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:20:37 by igenial           #+#    #+#             */
/*   Updated: 2023/05/29 09:52:19 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*for_free;

	while (*lst != NULL)
	{
		for_free = *lst;
		*lst = (*lst)->next;
		del(for_free->content);
		free(for_free);
	}
	lst = NULL;
}

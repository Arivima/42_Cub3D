/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:08:46 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/17 12:04:02 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vlstdelone(t_vlist *lst, void (*del)(void *))
{
	t_vlist	*temp;

	if (lst != NULL)
	{
		temp = lst->next;
		if (del != NULL)
			del(lst->content);
		free(lst);
		lst = temp;
	}
}

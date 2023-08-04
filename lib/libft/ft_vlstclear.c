/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.i>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:24:27 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:38:10 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vlstclear(t_vlist **lst, void (*del)(void *))
{
	t_vlist	*temp;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			temp = (*lst)->next;
			ft_vlstdelone(*lst, del);
			*lst = temp;
		}
	}
}

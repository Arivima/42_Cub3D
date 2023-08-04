/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.i>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:20:21 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:37:17 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vlstadd_front(t_vlist **lst, t_vlist *new)
{
	if (lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

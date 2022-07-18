/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.i>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:23:25 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:36:44 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vlstadd_back(t_vlist **lst, t_vlist *new)
{
	t_vlist	*last_ele;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_ele = ft_vlstlast(*lst);
			last_ele->next = new;
		}
	}
}

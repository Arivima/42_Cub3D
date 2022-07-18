/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:09:26 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:40:20 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vlstiter(t_vlist *lst, void (*f)(void *))
{
	if (f != NULL)
	{
		while (lst != NULL)
		{
			(f)(lst->content);
			lst = lst->next;
		}
	}
}

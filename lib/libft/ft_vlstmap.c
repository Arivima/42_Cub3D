/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:09:42 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:40:57 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vlist	*ft_vlstmap(t_vlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_vlist	*new;
	t_vlist	*tmp;
	t_vlist	*start;

	if (lst)
	{
		tmp = lst;
		start = ft_vlstnew(f(tmp->content));
		if (start == NULL)
			return (NULL);
		tmp = tmp->next;
		while (tmp)
		{
			new = ft_vlstnew(f(tmp->content));
			if (new == NULL)
			{
				ft_vlstclear(&start, del);
				return (NULL);
			}
			ft_vlstadd_back(&start, new);
			tmp = tmp->next;
		}
		return (start);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdi-lore <gdi-lore@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:08:35 by gdi-lore          #+#    #+#             */
/*   Updated: 2021/01/16 20:34:59 by gdi-lore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vlist	*ft_vlstnew(void *content)
{
	t_vlist	*new;

	new = (t_vlist *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:21:29 by avilla-m          #+#    #+#             */
/*   Updated: 2022/07/14 12:21:33 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_map(t_hold *hold)
{
	int	i;

	i = -1;
	debug("ft_print_map");
	while (hold->map[++i])
		printf("%s\n", hold->map[i]);
}

int	main(int ac, char **av)
{
	t_hold	hold;

	ft_memset(&hold, '\0', sizeof(t_hold));
	debug("parsing\n");
	if (parsing(ac, av, &hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
	debug("ft_init\n");
	if (ft_init(&hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
	debug("ft_execution\n");
	if (ft_execution(&hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
	debug("ft_set_mlx_loop\n");
	if (ft_set_mlx_loop(&hold) == ERR)
		return (ft_exit(&hold, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

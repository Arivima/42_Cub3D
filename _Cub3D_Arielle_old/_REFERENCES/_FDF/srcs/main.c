/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:43 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:09:45 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_printf("Wrong number of argument\n");
		exit(0);
	}
	init_mlx_and_img(&env);
	env.map = parse(argv[1], &env.draw->height, &env.draw->width);
	update_settings(&env);
	init_pixels(&env.map, env.draw);
	put_img(&env);
	mlx_hook(env.win, 2, 1L << 0, key_hook, &env);
	mlx_hook(env.win, 17, 1L << 2, exit_fdf, &env);
	ft_printf("Successfully reached end of program\n");
	mlx_loop(env.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:20 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/08 18:09:21 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// for testing
	// ft_printf("\n\nIn function ft_events-
	//-------\n\n");test_print_map(env->map, env->draw);
int	key_hook(int keycode, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (keycode == KEYCODE_PLUS)
		zoom(env, 2);
	if (keycode == KEYCODE_MINUS)
		zoom(env, 0.5);
	if (keycode == KEYCODE_LEFT)
		ft_event(env, &move_left);
	if (keycode == KEYCODE_RIGHT)
		ft_event(env, &move_right);
	if (keycode == KEYCODE_DOWN)
		ft_event(env, &move_down);
	if (keycode == KEYCODE_UP)
		ft_event(env, &move_up);
	key_hook_2(keycode, env);
	return (0);
}

int	key_hook_2(int keycode, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (keycode == KEYCODE_ENTER)
		change_projection(env);
	if (keycode == KEYCODE_SPACE_BAR)
		ft_event(env, &rotation);
	if (keycode == KEYCODE_C)
		ft_event(env, &color_update);
	if (keycode == KEYCODE_DELETE)
		reset_pixel(env);
	if (keycode == KEYCODE_ESC)
		exit_fdf(tmp);
	return (0);
}

void	ft_event(t_env *env, void (*f)(t_map ***, int, int, t_draw *))
{
	update_pixels(&env->map, env->draw, f);
	put_img(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:08:26 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 20:23:49 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int key_code, void *params)
{
	t_env	*env;

	env = params;
	if (key_code == KEY_R)
		reset(env);
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_C)
		change_color(env);
	move(env, key_code);
	key_press_extend(env, key_code);
	env->func(env);
	ft_put_image(env);
	return (0);
}

int	mouse_press(int button, int x, int y, void *params)
{
	t_env	*env;

	env = params;
	if (button == MOUSE_LEFT_BUTTON)
		env->fixed = (env->fixed + 1) % 2;
	if (button == MOUSE_SCROLL_UP)
		zoom_x(env, ZOOM, x, y);
	if (button == MOUSE_SCROLL_DOWN)
		zoom_x(env, 1.0 / ZOOM, x, y);
	env->func(env);
	ft_put_image(env);
	return (0);
}

int	mouse_move(int x, int y, void *params)
{
	t_env	*env;

	env = params;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT) \
				&& env->fixed == 0)
	{
		env->mouse_x = x;
		env->mouse_y = y;
	}
	env->func(env);
	ft_put_image(env);
	return (0);
}

int	window_close(void *params)
{
	(void ) params;
	exit(0);
}

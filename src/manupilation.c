/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manupilation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:30:01 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 22:08:56 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_env *env)
{
	env->color_index++;
	if (!env->colors[env->color_index])
		env->color_index = 0;
}

void	zoom_x(t_env *env, double zoom, int x, int y)
{
	double	cx;
	double	cy;

	if (env->max_iter <= 200 && zoom > 1)
		env->max_iter += 5;
	if (env->max_iter >= 50 && zoom < 1)
		env->max_iter -= 5;
	cx = ft_map(x, WIDTH, env->min_re, env->max_re);
	cy = ft_map(y, HEIGHT, env->min_im, env->max_im);
	env->max_re = (env->max_re - cx) / zoom + cx;
	env->min_re = (env->min_re - cx) / zoom + cx;
	env->max_im = (env->max_im - cy) / zoom + cy;
	env->min_im = (env->min_im - cy) / zoom + cy;
}

void	move(t_env *env, int keycode)
{
	double	w;
	double	h;

	w = (env->max_re - env->min_re) * STEP;
	h = (env->max_im - env->min_im) * STEP;
	if (keycode == KEY_UP)
	{
		env->max_im -= h;
		env->min_im -= h;
	}
	else if (keycode == KEY_DOWN)
	{
		env->max_im += h;
		env->min_im += h;
	}
	else if (keycode == KEY_LEFT)
	{
		env->max_re -= w;
		env->min_re -= w;
	}
	else if (keycode == KEY_RIGHT)
	{
		env->max_re += w;
		env->min_re += w;
	}
}

void	reset(t_env *env)
{
	env->max_iter = 100;
	env->min_re = -2.7 * WIDTH / 945;
	env->max_re = 1.7 * WIDTH / 945;
	env->min_im = -1.2 * HEIGHT / 540;
	env->max_im = 1.2 * HEIGHT / 540;
}

void	key_press_extend(t_env *env, int keycode)
{
	if (keycode == KEY_PLUS)
		env->max_iter += 15;
	if (keycode == KEY_MINUS)
	{
		if (env->max_iter > 50)
			env->max_iter -= 15;
	}
	if (keycode == KEY_Z && env->fractid == MULTI_MANDELBROT)
	{
		if (env->heads > 1)
			env->heads--;
	}
	if (keycode == KEY_X && env->fractid == MULTI_MANDELBROT)
	{
		env->heads++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:15:22 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/14 20:03:07 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	draw(t_env *env, t_complex z, t_complex c)
{
	int			i;
	int			color;
	double		tmp;

	i = -1;
	while (++i < env->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4)
			break ;
	}
	if (i == env->max_iter)
		color = env->colors[env->color_index]->tab[0];
	else
	{
		i = (i + 1) % env->colors[env->color_index]->size;
		if (i == 0)
			i++;
		color = env->colors[env->color_index]->tab[i];
	}
	return (color);
}

void	julia(t_env *env)
{
	int			x;
	int			y;
	double		im[HEIGHT + 1];
	t_complex	c[2];

	im[HEIGHT] = -2.7 + (1.7 + 2.7) * env->mouse_x / WIDTH;
	im[0] = -1.2 + (1.2 + 1.2) * env->mouse_y / HEIGHT;
	c[0].re = im[HEIGHT];
	c[0].im = im[0];
	y = -1;
	while (++y < HEIGHT)
		im[y] = env->min_im + (env->max_im - env->min_im) * y / HEIGHT;
	x = -1;
	while (++x < WIDTH)
	{
		im[HEIGHT] = env->min_re + (env->max_re - env->min_re) * x / WIDTH;
		y = -1;
		while (++y < HEIGHT)
		{
			c[1].re = im[HEIGHT];
			c[1].im = im[y];
			ft_put_pixel(env, x, y, draw(env, c[1], c[0]));
		}
	}
}

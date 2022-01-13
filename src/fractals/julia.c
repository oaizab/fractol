/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:15:22 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 21:21:48 by oaizab           ###   ########.fr       */
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
	t_complex	c;
	t_complex	z;

	im[HEIGHT] = -2.7 + (1.7 + 2.7) * env->mouse_x / WIDTH;
	im[0] = -1.2 + (1.2 + 1.2) * env->mouse_y / HEIGHT;
	c = ft_complex(im[HEIGHT], im[0]);
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
			z = ft_complex(im[HEIGHT], im[y]);
			ft_put_pixel(env, x, y, draw(env, z, c));
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:01:44 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/14 00:21:39 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	draw(t_env *env, t_complex c)
{
	t_complex	z;
	int			i;

	z = ft_complex(0, 0);
	i = -1;
	while (++i < env->max_iter && (z.re * z.re + z.im * z.im) <= 4)
	{
		z.tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = z.tmp;
		if (z.im < 0)
			z.im *= -1;
		if (z.re < 0)
			z.re *= -1;
	}
	if (i == env->max_iter)
		i = env->colors[env->color_index]->tab[0];
	else
	{
		i = (i + 1) % env->colors[env->color_index]->size;
		if (i == 0)
			i++;
		i = env->colors[env->color_index]->tab[i];
	}
	return (i);
}

void	burning_ship(t_env *env)
{
	int			x;
	int			y;
	double		re;
	double		im[HEIGHT];
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		im[y] = env->min_im + (env->max_im - env->min_im) * y / HEIGHT;
		y++;
	}
	x = 0;
	while (x < WIDTH)
	{
		re = env->min_re + (env->max_re - env->min_re) * x / WIDTH;
		y = 0;
		while (y < HEIGHT)
		{
			c = ft_complex(re, im[y]);
			ft_put_pixel(env, x, y, draw(env, c));
			y++;
		}
		x++;
	}
}

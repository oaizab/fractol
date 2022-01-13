/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:07:52 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 22:10:14 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_load_events(t_env *env, int fractid)
{
	mlx_hook(env->window, EVENT_KEY_PRESS, 0, key_press, env);
	mlx_hook(env->window, EVENT_CLOSE, 0, window_close, NULL);
	mlx_hook(env->window, EVENT_MOUSE_PRESS, 0, mouse_press, env);
	if (fractid == JULIA)
		mlx_hook(env->window, EVENT_MOUSE_MOVE, 0, mouse_move, env);
}

t_env	*ft_init_env(void *mlx, int width, int height)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->image = ft_new_image(mlx, width, height);
	if (!env->image)
		return (NULL);
	env->max_iter = 100;
	env->fixed = 0;
	env->color_index = 0;
	env->heads = 1;
	env->min_re = -2.7 * width / 945;
	env->max_re = 1.7 * width / 945;
	env->min_im = -1.2 * height / 540;
	env->max_im = 1.2 * height / 540;
	return (env);
}

t_fractfunc	*ft_load_function(int fractid)
{
	if (fractid == MANDELBROT || fractid == MULTI_MANDELBROT)
		return (mandelbrot);
	else if (fractid == JULIA)
		return (julia);
	return (NULL);
}

t_env	*ft_fractol_init(int fractid)
{
	void	*mlx;
	t_env	*env;

	mlx = mlx_init();
	env = ft_init_env(mlx, WIDTH, HEIGHT);
	if (!env)
		ft_exit_error("Image");
	env->window = mlx_new_window(mlx, WIDTH, HEIGHT, "OAizab xD");
	env->mlx = mlx;
	env->func = ft_load_function(fractid);
	if (fractid == MULTI_MANDELBROT)
		env->heads++;
	env->colors = ft_load_colors();
	env->fractid = fractid;
	return (env);
}

void	ft_exit_error(char *str)
{
	perror(str);
	exit(errno);
}

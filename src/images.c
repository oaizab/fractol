/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:08:08 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 19:52:43 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*ft_new_image(void *mlx, int width, int height)
{
	t_image	*image;
	void	*img;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (NULL);
	image->img = img;
	image->addr = mlx_get_data_addr(img, &image->bpp, \
			&image->size_line, &image->endian);
	image->width = width;
	image->height = height;
	return (image);
}

void	ft_put_pixel(t_env *env, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = env->image->addr + (y * env->image->size_line + \
			x * (env->image->bpp / 8));
	*(int *) pixel = color;
}

void	ft_put_image(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->window, \
			env->image->img, 0, 0);
	ft_show_info(env);
}

double	ft_map(int x, int max, double to_min, double to_max)
{
	return (to_min + (to_max - to_min) * x / max);
}

void	ft_show_info(t_env *env)
{
	char	*str_1;
	char	*tmp;

	if (env->fractid == JULIA)
		str_1 = ft_strjoin("Fractal : ", "Julia");
	else
		str_1 = ft_strjoin("Fractal : ", "Mandelbrot");
	mlx_string_put(env->mlx, env->window, 10, 10, 0x054A40, str_1);
	free(str_1);
	tmp = ft_itoa(env->color_index);
	str_1 = ft_strjoin("Color Palette : ", tmp);
	free(tmp);
	mlx_string_put(env->mlx, env->window, 10, 30, 0x054A40, str_1);
	free(str_1);
	tmp = ft_itoa(env->max_iter);
	str_1 = ft_strjoin("Max Iter : ", tmp);
	free(tmp);
	mlx_string_put(env->mlx, env->window, 10, 50, 0x054A40, str_1);
	free(str_1);
}

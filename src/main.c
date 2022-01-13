/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 04:50:55 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/14 00:09:09 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	int		fractid;

	if (argc != 2)
	{
		printf("Enter fractal id:\nUsage: ./fractol <fractal-id>\n");
		printf("Fractal id's :\n1 - Mandelbrot.\n2 - Julia.\n");
		printf("2 - Burning Ship\n");
		printf("\n-----------KEYS-----------\nZoom in/out: mouse scroll");
		printf("\nMove: arrows\nChange color: C\nFix julia: left click\n");
		printf("Image quality: +/-\nMulti-mandelbrot heads: Z/X\n");
		return (0);
	}
	fractid = ft_atoi(argv[1]);
	if (fractid < 1 || fractid > 3)
	{
		printf("Invalid fractal id.\n");
		return (0);
	}
	env = ft_fractol_init(fractid);
	ft_load_events(env, fractid);
	env->func(env);
	ft_put_image(env);
	mlx_loop(env->mlx);
	return (0);
}

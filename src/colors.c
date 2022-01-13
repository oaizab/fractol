/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 05:08:18 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/13 03:03:05 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*ft_get_color(char *path)
{
	int		fd;
	t_color	*color;
	char	*str;
	int		i;

	fd = open(path, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		ft_exit_error(path);
		color = malloc(sizeof(t_color));
	if (!color)
		ft_exit_error("Color");
	color->size = ft_atoi(str);
	free(str);
	color->tab = ft_calloc(color->size, sizeof(int));
	if (!color->tab)
		ft_exit_error("Color");
	i = 0;
	while (i < color->size)
	{
		str = get_next_line(fd);
		color->tab[i++] = ft_atoi(str);
		free(str);
	}
	return (close(fd), color);
}

t_color	**ft_load_colors(void)
{
	t_color	**colors;
	int		fd;
	char	*str;
	int		colors_number;
	int		i;

	fd = open("./colors/index.col", O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		ft_exit_error("./colors/index.col");
	colors_number = ft_atoi(str);
	free(str);
	colors = ft_calloc(colors_number + 1, sizeof(t_color));
	if (!colors)
		ft_exit_error("Colors");
	i = 0;
	while ((colors_number-- > 0))
	{
		str = get_next_line(fd);
		*ft_strchr(str, '\n') = '\0';
		colors[i++] = ft_get_color(str);
		free(str);
	}
	close(fd);
	return (colors);
}

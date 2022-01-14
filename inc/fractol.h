/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:35:37 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/14 01:34:01 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_mlx_keys.h"
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

//
// Defining utility
//

# define ZOOM 2.5
# define STEP 0.05

//
// Defining resolution
//

# define WIDTH 945
# define HEIGHT 540

//
// Defining fractal ids
//

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define MULTI_MANDELBROT 4

//
// Defining struct types
//

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_color
{
	int	*tab;
	int	size;
}				t_color;

typedef struct s_env	t_env;

typedef void			t_fractfunc(t_env *env);

struct s_env
{
	t_image		*image;
	t_fractfunc	*func;
	t_color		**colors;
	void		*mlx;
	void		*window;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			mouse_x;
	int			mouse_y;
	int			max_iter;
	int			color_index;
	int			fixed;
	int			heads;
	int			fractid;
};

typedef struct s_complex
{
	double	re;
	double	im;
	double	tmp;
}				t_complex;

//
// Manupilation functions
//

void		change_color(t_env *env);
void		zoom_x(t_env *env, double zoom, int x, int y);
void		move(t_env *env, int keycode);
void		reset(t_env *env);
void		key_press_extend(t_env *env, int keycode);

//
// Complex functions
//

t_complex	ft_complex(double im, double re);
t_complex	ft_add_complex(t_complex c_1, t_complex c_2);
t_complex	ft_pow_complex(t_complex c, int n);
t_complex	ft_mul_complex(t_complex c_1, t_complex c_2);
double		ft_magnitude(t_complex c);

//
// Fractals functions
//

void		mandelbrot(t_env *env);
void		julia(t_env *env);
void		burning_ship(t_env *env);
void		multi_mandelbrot(t_env *env);

//
// Envirenment functions
//

void		ft_load_events(t_env *env, int fractid);
t_env		*ft_init_env(void *mlx, int width, int height);
t_env		*ft_fractol_init(int fractid);
t_fractfunc	*ft_load_function(int fractid);
void		ft_exit_error(char *str);

//
// Events functions
//

int			key_press(int key_code, void *params);
int			mouse_press(int button, int x, int y, void *params);
int			mouse_move(int x, int y, void *params);
int			window_close(void *params);

//
// Images functions
//

t_image		*ft_new_image(void *mlx, int width, int height);
void		ft_put_pixel(t_env *env, int x, int y, int color);
void		ft_put_image(t_env *env);
double		ft_map(int x, int max, double to_min, double to_max);
void		ft_show_info(t_env *env);

//
// Colors functions
//

t_color		**ft_load_colors(void);
t_color		*ft_get_color(char *path);

#endif
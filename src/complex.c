/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:46:25 by oaizab            #+#    #+#             */
/*   Updated: 2022/01/12 21:25:08 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_complex(double re, double im)
{
	t_complex	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_complex	ft_add_complex(t_complex c_1, t_complex c_2)
{
	t_complex	c;

	c.re = c_1.re + c_2.re;
	c.im = c_1.im + c_2.im;
	return (c);
}

t_complex	ft_mul_complex(t_complex c_1, t_complex c_2)
{
	t_complex	z;

	z.re = c_1.re * c_2.re - c_1.im * c_2.im;
	z.im = c_1.re * c_2.im + c_1.im * c_2.re;
	return (z);
}

t_complex	ft_pow_complex(t_complex c, int n)
{
	t_complex	z;

	z = ft_complex(c.re, c.im);
	while (n > 1)
	{
		z = ft_mul_complex(z, c);
		n--;
	}
	return (z);
}

double	ft_magnitude(t_complex c)
{
	double	mag;

	mag = sqrt(c.re * c.re + c.im * c.im);
	return (mag);
}

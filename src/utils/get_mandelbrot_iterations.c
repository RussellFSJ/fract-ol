/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mandelbrot_iterations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:35:16 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 22:20:50 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	compute_iter(double c_re, double c_im);

int	get_mandelbrot_iterations(t_fractol *f, int x, int y)
{
	double	c_re;
	double	c_im;

	c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	return (compute_iter(c_re, c_im));
}

static int	compute_iter(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	int		iterations;
	double	tmp;

	z_re = 0.0;
	z_im = 0.0;
	iterations = 0;
	while (z_re * z_re + z_im * z_im <= 4.0 && iterations < MAX_ITER)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2.0 * z_re * z_im + c_im;
		z_re = tmp;
		iterations++;
	}
	return (iterations);
}

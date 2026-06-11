/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:11:56 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/11 23:06:12 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_init(t_fractol *f);
static void	draw_mandelbrot(t_fractol *f);
static int	compute_pixel(t_fractol *f, int x, int y);
static int	mandelbrot_iterations(double c_re, double c_im);

void	mandelbrot(t_fractol *f, char **argv)
{
	mandelbrot_init(f);
	draw_mandelbrot(f);
}

static void	mandelbrot_init(t_fractol *f)
{
	f->zoom = 1.0;
	f->move_x = 0.0;
	f->move_y = 0.0;
	f->c_re = 0.0;
	f->c_im = 0.0;
}

static void	draw_mandelbrot(t_fractol *f)
{
	int	y;
	int	x;
	int	iterations;
	int	colour;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iterations = compute_pixel(f, x, y);
			if (iterations == MAX_ITER)
				colour = 0x000000;
			else
				colour = (int)((double)iterations / MAX_ITER * 0xFFFFFF);
			put_pixel(f, x, y, colour);
			x++;
		}
		y++;
	}
}

static int	compute_pixel(t_fractol *f, int x, int y)
{
	double	c_re;
	double	c_im;

	c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	return (mandelbrot_iterations(c_re, c_im));
}

static int	mandelbrot_iterations(double c_re, double c_im)
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

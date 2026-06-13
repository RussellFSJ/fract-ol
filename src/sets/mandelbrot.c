/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:11:56 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 19:14:38 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_init(t_fractol *f);

void	mandelbrot(t_fractol *f)
{
	mandelbrot_init(f);
	draw_fractal(f);
}

static void	mandelbrot_init(t_fractol *f)
{
	f->zoom = 1.0;
	f->move_x = 0.0;
	f->move_y = 0.0;
	f->c_re = 0.0;
	f->c_im = 0.0;
}

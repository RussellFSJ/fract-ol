/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 23:46:50 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/14 00:05:14 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	adjust_zoom(t_fractol *f, int button);
static void	recenter(t_fractol *f, int x, int y, double old_re, double old_im);

int	handle_mouse_event(int button, int x, int y, t_fractol *f)
{
	double	old_re;
	double	old_im;

	old_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	old_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	adjust_zoom(f, button);
	recenter(f, x, y, old_re, old_im);
	draw_fractal(f);
	return (0);
}

static void	adjust_zoom(t_fractol *f, int button)
{
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
}

static void	recenter(t_fractol *f, int x, int y, double old_re, double old_im)
{
	double	new_re;
	double	new_im;

	new_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	new_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	f->move_x += old_re - new_re;
	f->move_y += old_im - new_im;
}

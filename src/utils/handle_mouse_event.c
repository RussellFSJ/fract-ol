/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 23:46:50 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/15 15:47:50 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	recenter_zoom(t_fractol *f, int button, int x, int y);

int	handle_mouse_event(int button, int x, int y, t_fractol *f)
{
	recenter_zoom(f, button, x, y);
	draw_fractal(f);
	return (0);
}

static void	recenter_zoom(t_fractol *f, int button, int x, int y)
{
	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;

	old_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	old_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	if (button != 4 && button != 5)
		return ;
	else if (button == 4)
		f->zoom *= ZOOM;
	else if (button == 5)
		f->zoom /= ZOOM;
	new_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->move_x;
	new_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->move_y;
	f->move_x += old_re - new_re;
	f->move_y += old_im - new_im;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:28:20 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 20:29:17 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_init(t_fractol *f, char **argv);

void	julia(t_fractol *f, char **argv)
{
	julia_init(f, argv);
	draw_fractal(f);
}

static void	julia_init(t_fractol *f, char **argv)
{
	f->zoom = 1.0;
	f->move_x = 0.0;
	f->move_y = 0.0;
	f->c_re = ft_atof(argv[2]);
	f->c_im = ft_atof(argv[3]);
}


	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:14:51 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/08 17:55:46 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(t_fractol *f, char *err_msg);

void	fractol(t_fractol *f, char **argv)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		handle_error(f, "Failed to connect to graphical system.\n");
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->type);
	if (!f->window)
		handle_error(f, "Failed to create mlx window.\n");
	f->image = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->image)
		handle_error(f, "Failed to create image.\n");
	f->address = mlx_get_data_addr(f->image, &f->bpp, &f->line_len, &f->endian);
	if (!f->address)
		handle_error(f, "Failed to get image address.\n");
	add_event_hooks(f);
	if (is_mandelbrot(f->type))
		mandelbrot(f);
	else
		julia(f, argv);
	mlx_loop(f->mlx);
}

static void	handle_error(t_fractol *f, char *err_msg)
{
	handle_cleanup(f);
	ft_printf(err_msg);
	exit(EXIT_FAILURE);
}

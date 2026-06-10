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

void	fractol(char **argv)
{
	t_fractol	*f;

	f = malloc(sizeof(t_fractol));
	if (!f)
		return ;
	f->type = argv[1];
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_printf("Failed to connect to graphical system.");
		return ;
	}
	f->window = mlx_new_window(f->mlx, WIDTH, HEIGHT, f->type);
	if (!f->window)
	{
		ft_printf("Failed to create mlx window.");
		return ;
	}
	if (is_mandelbrot(f->type))
		mandelbrot(f, argv);
	else
		julia(f, argv);
	mlx_loop(f->mlx);
	free(f);
	return ;
}

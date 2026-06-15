/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:33:37 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/15 15:00:37 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *f)
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
			if (is_mandelbrot(f->type))
				iterations = get_mandelbrot_iterations(f, x, y);
			else
				iterations = get_julia_iterations(f, x, y);
			colour = get_colour(iterations);
			put_pixel(f, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
}

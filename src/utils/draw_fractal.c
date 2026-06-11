/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:33:37 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/11 23:52:23 by rfoo             ###   ########.fr       */
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
			iterations = get_iterations(f, x, y);
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

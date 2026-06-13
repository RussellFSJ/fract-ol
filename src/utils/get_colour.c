/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:45:01 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 23:18:12 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_colour(int iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;
	
	if (iterations == MAX_ITER)
		return (0x000000);
	t = (double)iterations / MAX_ITER;
	r = (int)((sin(5 * PI * t) * 0.5 + 0.5) * 255);
	g = (int)((sin(7 * PI * t + PI/4) * 0.5 + 0.5) * 255);
	b = (int)((sin(11 * PI * t + PI/2) * 0.5 + 0.5) * 255);
	return ((r << 16) | (g << 8) | b);
}

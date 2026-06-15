/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:13:49 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/15 15:02:06 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int colour)
{
	char	*dest;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	if (!f || !f->address)
		return ;
	dest = f->address + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dest = colour;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:13:49 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/11 21:19:22 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int colour)
{
	char	*dest;

	dest = f->address + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int*)dest = colour;
}

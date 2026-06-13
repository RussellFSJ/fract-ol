/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:47:00 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 20:47:26 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void handle_cleanup(t_fractol *f)
{
	if (f)
	{
		if (f->image)
			mlx_destroy_image(f->mlx, f->image);
		if (f->window)
			mlx_destroy_window(f->mlx, f->window);
		free(f);
	}
}

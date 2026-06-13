/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:45:49 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 21:06:14 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int handle_exit(t_fractol *f);
static int	handle_key(int key, t_fractol *f);

void	add_event_hooks(t_fractol *f)
{
	mlx_hook(f->window, 17, 0, handle_exit, f);
	mlx_key_hook(f->window, handle_key, f);
}

static int	handle_exit(t_fractol *f)
{
	handle_cleanup(f);
	exit(EXIT_SUCCESS);
	return(0);
}

static int	handle_key(int key, t_fractol *f)
{
	if (key == 65307)
		return handle_exit(f);
	return (0);
}

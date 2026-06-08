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

void	fractol(int size_x, int size_y, char *title)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("Failed to connect to graphical system.");
		return ;
	}
	window = mlx_new_window(mlx, size_x, size_y, title);
	if (!window)
	{
		ft_printf("Failed to create mlx window.");
		return ;
	}
	mlx_loop(mlx);
	return ;
}

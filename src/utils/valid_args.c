/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:54:47 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/10 21:12:58 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_args(int argc, char **argv)
{
	if (argc == 2 && is_mandelbrot(argv[1]))
		return (1);
	else if (argc == 4 && is_julia(argv[1]))
	{
		if (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3]))
		{
			ft_printf("Re/Im are doubles. Usage: ./fractol julia <Re> <Im>\n");
			return (0);
		}
		return (1);
	}
	else
	{
		ft_printf("Usage: ./fractol mandelbrot OR ./fractol julia <Re> <Im>\n");
		return (0);
	}
}

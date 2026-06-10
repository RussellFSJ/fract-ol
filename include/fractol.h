/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 23:53:25 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/11 00:05:43 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_fractol
{	
	void	*mlx;
	void	*window;
	void	*image;
	void	*address;

	char	*type;

	int		bpp;
	int		line_len;
	int		endian;

	double	zoom;
	double	move_x;
	double	move_y;

	double	re;
	double	im;
}	t_fractol;

int	ft_isdouble(const char *str);
int	is_julia(char *str);
int	is_mandelbrot(char *str);
int	valid_args(int argc, char **argv);


#endif
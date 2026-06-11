/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 23:53:25 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/11 23:52:57 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
typedef struct s_fractol
{	
	void	*mlx;
	void	*window;
	char	*type;
	double	zoom;
	double	move_x;
	double	move_y;
	double	c_re;
	double	c_im;

	
	void	*image;
	void	*address;
	int		bpp;
	int		line_len;
	int		endian;




}	t_fractol;

void	draw_fractal(t_fractol *f);
int		ft_isdouble(const char *str);
int		get_iterations(t_fractol *f, int x, int y);
int		is_julia(char *str);
int		is_mandelbrot(char *str);
void	put_pixel(t_fractol *f, int x, int y, int colour);
int		valid_args(int argc, char **argv);

#endif
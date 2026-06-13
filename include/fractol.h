/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 23:53:25 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/13 23:12:57 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100
# define PI 3.14159265358979323846
typedef struct s_fractol
{	
	char	*type;
	void	*mlx;
	void	*window;
	void	*image;
	void	*address;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	move_x;
	double	move_y;
	double	c_re;
	double	c_im;
}	t_fractol;

void	add_event_hooks(t_fractol *f);
void	draw_fractal(t_fractol *f);
double	ft_atof(const char *nptr);
int		ft_isdouble(const char *str);
int		get_colour(int iterations);
int		get_julia_iterations(t_fractol *f, int x, int y);
int		get_mandelbrot_iterations(t_fractol *f, int x, int y);
void	handle_cleanup(t_fractol *f);
int		is_julia(char *str);
int		is_mandelbrot(char *str);
void	put_pixel(t_fractol *f, int x, int y, int colour);
int		valid_args(int argc, char **argv);
void	julia(t_fractol *f, char **argv);
void	mandelbrot(t_fractol *f);
void	fractol(char **argv);

#endif
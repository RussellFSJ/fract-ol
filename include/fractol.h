/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 23:53:25 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/10 16:01:09 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_fractol
{	
	int	size_x;
	int	size_y;
}	t_fractol;

int	ft_isdouble(const char *str);
int	valid_args(int argc, char **argv);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfoo <rfoo@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 23:58:45 by rfoo              #+#    #+#             */
/*   Updated: 2026/06/15 13:34:00 by rfoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(t_fractol *f, char *err_msg);

int	main(int argc, char **argv)
{
	t_fractol	*f;

	if (!valid_args(argc, argv))
		return (EXIT_FAILURE);
	f = malloc(sizeof(t_fractol));
	if (!f)
		handle_error(NULL, "Failed to allocate memory for t_fractol.\n");
	f->type = argv[1];
	fractol(f, argv);
	handle_cleanup(f);
	return (EXIT_SUCCESS);
}

static void	handle_error(t_fractol *f, char *err_msg)
{
	handle_cleanup(f);
	ft_printf(err_msg);
	exit(EXIT_FAILURE);
}
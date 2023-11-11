/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:35:31 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/11 19:34:08 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	/* This mlx function creates a returns a pointer
	to a new window with a given size and name */
	window.mlx = mlx_new_window(mlx, widht, height, name);

	// Allocate memory for window.size
    window.size = malloc(sizeof(t_size));
	window.size->w = widht;
	window.size->h = height;

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.mlx, 17, 0, ft_close, 0);

	return (window);
}
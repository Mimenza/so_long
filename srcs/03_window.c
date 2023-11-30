/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:35:31 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 15:42:25 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//This function closes the window.
int	ft_close(void)
{
	exit(0);
}

//This function creates a window struct.
t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.win = mlx_new_window(mlx, widht, height, name);
	window.size = malloc(sizeof(t_size));
	window.size->w = widht;
	window.size->h = height;
	window.mlx = mlx;
	mlx_hook(window.win, 17, 0, ft_close, 0);
	return (window);
}

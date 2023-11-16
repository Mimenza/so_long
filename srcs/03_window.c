/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:35:31 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/16 16:54:30 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_close(void)
{
	exit(0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.win = mlx_new_window(mlx, widht, height, name);
	window.size = malloc(sizeof(t_size));
	window.size->w = widht;
	window.size->h = height;
	mlx_hook(window.win, 17, 0, ft_close, 0);
	return (window);
}

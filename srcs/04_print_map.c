/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:08 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 14:27:18 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void ft_print_map(t_game *game)
{
	int		x;
	int		y;
	char 	**grid;


	grid = game->map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.img[0], x * PX, y * PX);
			if (grid[y][x] == '1')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.img[1], x * PX, y * PX);
			if (grid[y][x] == 'P')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.img[3], x * PX, y * PX);
			if (grid[y][x] == 'C')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.img[2], x * PX, y * PX);
			if (grid[y][x] == 'E')
				mlx_put_image_to_window(game->window.mlx, game->window.win, game->window.img[7], x * PX, y * PX);
			x++;
		}
		y++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:08 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/20 13:54:42 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_put_img(t_game *game, int x, int y)
{
	char	**grid;

	grid = game->map.grid;
	mlx_put_image_to_window(game->window.mlx, \
	game->window.win, game->window.img[0], x * PX, y * PX);
	if (grid[y][x] == '1')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[1], x * PX, y * PX);
	if (grid[y][x] == 'C')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[2], x * PX, y * PX);
	if (grid[y][x] == 'E')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[7], x * PX, y * PX);
	if (grid[y][x] == 'B')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[17], x * PX, y * PX);
}

void	ft_print_map(t_game *game)
{
	int		x;
	int		y;
	char	**grid;

	grid = game->map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			ft_put_img(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_info(*game);
}

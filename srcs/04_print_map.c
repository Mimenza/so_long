/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:08 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/11 08:20:21 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Aux function which prints the map into the window.
static void	ft_put_img(t_game *game, int x, int y, int enemy_nbr)
{
	char	**grid;

	grid = game->map.grid;
	mlx_put_image_to_window(game->window.mlx, \
	game->window.win, game->window.img[0], x * PX, y * PX);
	if (grid[y][x] == '1')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[1], x * PX, y * PX);
	if (grid[y][x] == 'C')
		mlx_put_image_to_window(game->window.mlx, game->window.win, \
		game->window.img[5], x * PX, y * PX);
	if (grid[y][x] == 'E')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[4], x * PX, y * PX);
	if (grid[y][x] == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win, \
		game->window.img[3], game->p.pos.x * PX, \
		game->p.pos.y * PX + y);
}

//Main function which prints the map into the window.
void	ft_print_map(t_game *game)
{
	int		x;
	int		y;
	char	**grid;
	int		enemy;

	enemy = 0;
	grid = game->map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			ft_put_img(game, x, y, enemy);
			x++;
		}
		y++;
	}
}

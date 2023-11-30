/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:08 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 17:05:33 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Aux function which prints the map into the window.
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

//Main function which prints the map into the window.
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

//Prints info on the window.
void	ft_print_info(t_game game)
{
	mlx_string_put(game.window.mlx, game.window.win, 5, 10, 0x00000000, \
	"MOVES");
	mlx_string_put(game.window.mlx, game.window.win, 5, 20, 0x00000000, \
	ft_itoa(game.steps));
	mlx_string_put(game.window.mlx, game.window.win, 5, 30, 0x00000000, \
	"COLLECTABLES:");
	mlx_string_put(game.window.mlx, game.window.win, 5, 40, 0x00000000, \
	ft_itoa(game.coll));
	mlx_string_put(game.window.mlx, game.window.win, 10, 40, 0x00000000, \
	"/");
	mlx_string_put(game.window.mlx, game.window.win, 15, 40, 0x00000000, \
	ft_itoa(game.map.n_coll));
}

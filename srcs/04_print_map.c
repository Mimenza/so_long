/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:11:08 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/04 08:21:59 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Aux function which prints the map into the window.
void	ft_put_img(t_game *game, int x, int y, int enemy_nbr)
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
		game->window.img[12 + game->coll_skin], x * PX, y * PX);
	if (grid[y][x] == 'E')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[game->exit.skin], x * PX, y * PX);
	if (grid[y][x] == 'B')
		mlx_put_image_to_window(game->window.mlx, \
		game->window.win, game->window.img[game->enemy[enemy_nbr].skin], \
		x * PX, y * PX);
	if (grid[y][x] == 'P')
		mlx_put_image_to_window(game->window.mlx, game->window.win, \
		game->window.img[game->p.skin], game->p.pos.x * PX, \
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
	ft_print_info(*game);
}

//Prints info on the window.
void	ft_print_info(t_game game)
{
	mlx_string_put(game.window.mlx, game.window.win, 5, \
	game.window.size->h - 10, 0x00FFFFFF, "MOVES:");
	mlx_string_put(game.window.mlx, game.window.win, 45, \
	game.window.size->h - 10, 0x00FFFFFF, ft_itoa(game.steps));
	mlx_string_put(game.window.mlx, game.window.win, 5, \
	game.window.size->h - 30, 0x00FFFFFF, "COLLECTABLES:");
	mlx_string_put(game.window.mlx, game.window.win, 90, \
	game.window.size->h - 30, 0x00FFFFFF, ft_itoa(game.coll));
	mlx_string_put(game.window.mlx, game.window.win, 100, \
	game.window.size->h - 30, 0x00FFFFFF, "/");
	mlx_string_put(game.window.mlx, game.window.win, 110, \
	game.window.size->h - 30, 0x00FFFFFF, ft_itoa(game.map.n_coll));
	mlx_string_put(game.window.mlx, game.window.win, 130, \
	game.window.size->h - 30, 0x00FFFFFF, "COLLECT ALL THE COINS \
	ACROSS THE MAP AND SAVE THEM IN THE CHEST!");
}

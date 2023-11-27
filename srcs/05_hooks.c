/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/27 09:42:06 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void ft_animate_coins(t_game game)
{
	char **grid;
	int y;
	int x;
	int y2;
	static int	dir2;
	static int	frame2;
	
	y = 0;
	grid = game.map.grid;
	//mlx_clear_window(game.window.mlx, game.window.win);
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
			{
				y2 = y;
				if (frame2 == ANIMATION_FRAMES / 2)
					dir2 = 1;
				else if (frame2 == 0)
					dir2 = 0;
				if (dir2 == 0)
				{
					y2 += 5;
					frame2 += 1;
				}
				else if (dir2 == 1)
				{
					y2 -= 5;
					frame2 -= 1;
				}
				//ft_print_map(&game);
				mlx_put_image_to_window(game.window.win, game.window.win, game.window.img[2], x * PX, y * PX +  y2);
			}
			x++;
		}
		y++;
	}
}

void ft_animate_player(t_game game)
{
	int			x;
	int			y;
	static int	dir;
	static int	frame;

	y = game.player.y_pos;
	mlx_clear_window(game.window.mlx, game.window.win);
	if (frame == ANIMATION_FRAMES)
		dir = 1;
	else if (frame == 0)
		dir = 0;
	if (dir == 0)
	{
		y += 5;
		frame += 1;
	}
	else if (dir == 1)
	{
		y -= 5;
		frame -= 1;
	}
	ft_print_map(&game);
	mlx_put_image_to_window(game.window.mlx, game.window.win, \
	game.window.img[3], game.player.x_pos * PX, game.player.y_pos * 48 + y);
}

int	ft_input(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_clear_window(game->window.mlx, game->window.win);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->window.mlx, game->window.win);
		ft_close();
	}
	else if (key == KEY_D || key == KEY_RIGHT)
		ft_move_player(game, game->player.x_pos + 1, game->player.y_pos);
	else if (key == KEY_A || key == KEY_LEFT)
		ft_move_player(game, game->player.x_pos - 1, game->player.y_pos);
	else if (key == KEY_W || key == KEY_UP)
		ft_move_player(game, game->player.x_pos, game->player.y_pos - 1);
	else if (key == KEY_S || key == KEY_DOWN)
		ft_move_player(game, game->player.x_pos, game->player.y_pos + 1);
	ft_randomize(game);
	ft_print_map(game);
	return (0);
}

int	ft_update(void *param)
{
	t_game		*game;
	
	
	game = (t_game *)param;
	ft_animate_player(*game);
	//ft_animate_coins(*game);
	
	return (0);
}

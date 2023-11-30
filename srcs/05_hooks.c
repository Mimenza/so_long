/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 13:25:53 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_animate_player(t_game game)
{
	int			x;
	int			y;
	static int	dir;
	static int	frame;

	y = game.player.position.y;
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
	ft_randomize(&game);
	ft_print_map(&game);
	mlx_put_image_to_window(game.window.mlx, game.window.win, game.window.img[game.player.skin], game.player.position.x * PX, game.player.position.y * 48 + y);
}

void	ft_input2(int key, t_game *game)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->player.skin = 6;
		ft_move_player(game, game->player.position.x + 1, game->player.position.y);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game->player.skin = 5;
		ft_move_player(game, game->player.position.x - 1, game->player.position.y);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		game->player.skin = 4;
		ft_move_player(game, game->player.position.x, game->player.position.y - 1);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game->player.skin = 3;
		ft_move_player(game, game->player.position.x, game->player.position.y + 1);
	}
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
	ft_input2(key, game);
	ft_print_map(game);
	return (0);
}

int	ft_update(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	ft_animate_player(*game);
	return (0);
}

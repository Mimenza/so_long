/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 15:51:13 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Funtion which animates the player.
void	ft_animate_player(t_game game)
{
	int			x;
	int			y;
	static int	dir;
	static int	frame;

	y = game.p.pos.y;
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
	mlx_put_image_to_window(game.window.mlx, game.window.win, \
	game.window.img[game.p.skin], game.p.pos.x * PX, game.p.pos.y * 48 + y);
}

//Input loop aux function.
void	ft_input2(int key, t_game *game)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->p.skin = 6;
		ft_move_player(game, game->p.pos.x + 1, \
		game->p.pos.y);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game->p.skin = 5;
		ft_move_player(game, game->p.pos.x - 1, \
		game->p.pos.y);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		game->p.skin = 4;
		ft_move_player(game, game->p.pos.x, \
		game->p.pos.y - 1);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game->p.skin = 3;
		ft_move_player(game, game->p.pos.x, \
		game->p.pos.y + 1);
	}
}

//Input loop main function.
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

//Update loop function.
int	ft_update(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	ft_animate_player(*game);
	return (0);
}

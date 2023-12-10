/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/10 19:21:55 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

//Funtion which animates the coins.
static void	ft_animate_coin(t_game *game)
{
	static int	c_frame ;

	if (c_frame % (COIN_ROTATION / 8) == 0 && c_frame != 0)
		game->coll_skin += 1;
	if (c_frame == COIN_ROTATION)
	{
		c_frame = 0;
		game->coll_skin = 0;
	}
	c_frame++;
}

//Input loop aux function.
static void	ft_input2(int key, t_game *game)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->p.skin = 9;
		ft_move_player(game, game->p.pos.x + 1, \
		game->p.pos.y);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game->p.skin = 8;
		ft_move_player(game, game->p.pos.x - 1, \
		game->p.pos.y);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		game->p.skin = 6;
		ft_move_player(game, game->p.pos.x, \
		game->p.pos.y - 1);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game->p.skin = 7;
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
	mlx_clear_window(game->window.mlx, game->window.win);
	ft_randomize(game);
	ft_animate_coin(game);
	ft_print_map(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/11 08:20:27 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Input loop aux function.
static void	ft_input2(int key, t_game *game)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		ft_move_player(game, game->p.pos.x + 1, \
		game->p.pos.y);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		ft_move_player(game, game->p.pos.x - 1, \
		game->p.pos.y);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		ft_move_player(game, game->p.pos.x, \
		game->p.pos.y - 1);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
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

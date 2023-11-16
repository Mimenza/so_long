/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:58:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/16 16:56:38 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

// Any function that you hook with the key event must be like this:
// Recibing and int for the code of the key pressed
// and a void pointer in case you need to recibe someting 
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
	ft_print_map(game);
	return (0);
}

int	ft_update(void *param)
{
	return (0);
}

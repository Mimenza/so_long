/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/01 23:00:39 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Prints the #of coins and opens the exit
void	ft_check_coin(t_game *game)
{
	ft_printf("\033[0;32m COIN COLLECTED! %i/%i \033[0m\n", \
			game->coll, game->map.n_coll);
	if (game->coll == game->map.n_coll)
		game->exit.skin = 11;
}
//Aux function which moves the player.
void	ft_move_player2(t_game *game, int x, int y)
{
	mlx_clear_window(game->window.mlx, game->window.win);
	game->map.grid[y][x] = 'P';
	if ((game->coll != game->map.n_coll) && \
	(game->exit.position.x == game->p.pos.x) \
	&& (game->exit.position.y == game->p.pos.y))
		game->map.grid[game->p.pos.y][game->p.pos.x] = 'E';
	else
		game->map.grid[game->p.pos.y][game->p.pos.x] = '0';
	game->p.pos.y = y;
	game->p.pos.x = x;
	game->steps++;
	ft_printf("NUMERO DE MOVIMIENTOS DADOS : %i\n", game->steps);
}

//Main function which moves the player.
int	ft_move_player(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] && game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
		{
			game->coll += 1;
			ft_check_coin(game);
		}
		if (game->map.grid[y][x] == 'E')
		{
			if (game->coll == game->map.n_coll)
			{
				ft_printf("\033[0;32m COMPLETED! \033[0m\n");
				ft_close();
			}
			ft_printf("\033[0;32m COLLECT ALL THE COINS FIRST! \033[0m\n");
		}
		if (game->map.grid[y][x] == 'B')
		{
			ft_close();
		}
		ft_move_player2(game, x, y);
		return (1);
	}
	return (0);
}

//Main function which moves the enemy.
int	ft_move_enemy(t_game *game, int x, int y, t_position pos)
{
	if (game->map.grid[y][x] && (game->map.grid[y][x] == 'P' \
	|| game->map.grid[y][x] == '0'))
	{
		if (game->map.grid[y][x] == 'P')
		{
			ft_printf("\033[0;32m PLAYER ELIMINATE \033[0m\n");
			ft_close();
		}
		mlx_clear_window(game->window.mlx, game->window.win);
		game->map.grid[y][x] = 'B';
		game->map.grid[pos.y][pos.x] = '0';
		return (1);
	}
	else
		ft_select_movement(*game, pos.y, pos.x, (ft_rand()));
	return (0);
}

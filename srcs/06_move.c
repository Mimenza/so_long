/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:16 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_move_player2(t_game *game, int x, int y)
{
	mlx_clear_window(game->window.mlx, game->window.win);
	game->map.grid[y][x] = 'P';
	if ((game->coll != game->map.n_coll) && \
	(game->exit.position.x == game->player.position.x) \
	&& (game->exit.position.y == game->player.position.y))
		game->map.grid[game->player.position.y][game->player.position.x] = 'E';
	else
		game->map.grid[game->player.position.y][game->player.position.x] = '0';
	game->player.position.y = y;
	game->player.position.x = x;
	game->steps++;
	ft_printf("NUMERO DE MOVIMIENTOS DADOS : %i\n", game->steps);
}

int	ft_move_player(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] && game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
		{
			game->coll += 1;
			ft_printf("\033[0;32m MONEDA RECOGIDA! %i/%i \033[0m\n", game->coll, game->map.n_coll);
		}
		if (game->map.grid[y][x] == 'E')
		{
			if (game->coll == game->map.n_coll)
			{
				ft_printf("\033[0;32m JUEGO COMPLETADO!! \033[0m\n");
				ft_close();
			}
			else
				ft_printf("\033[0;32m PRIMERO TIENES QUE RECOGER TODAS LAS MONEDAS!! \033[0m\n");
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

void	ft_move_enemy2(t_game *game, int x, int y, int ox, int oy)
{
	mlx_clear_window(game->window.mlx, game->window.win);
	game->map.grid[y][x] = 'B';
	game->map.grid[oy][ox] = '0';
}

int	ft_move_enemy(t_game *game, int x, int y, int ox, int oy)
{
	if (game->map.grid[y][x] && (game->map.grid[y][x] == 'P' \
	|| game->map.grid[y][x] == '0'))
	{
		if (game->map.grid[y][x] == 'P')
		{
			ft_printf("\033[0;32m PLAYER ELIMINATE \033[0m\n");
			ft_close();
		}
		ft_move_enemy2(game, x, y, ox, oy);
		return (1);
	}
	else
		ft_select_movement(*game, oy, ox, (ft_rand()));
	return (0);
}

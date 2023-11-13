/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:20:52 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 16:11:28 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_move_player(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] && game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
		{
			//RECOGEMOS LA MONEDA
			game->coll += 1;
		}

		if (game->map.grid[y][x] == 'E')
		{
			//SALIMOS
			if (game->coll == game->map.n_coll)
			{
				ft_printf("JUEGO COMPLETADO!!");
				ft_close();
			}
		}
		
		//TE PUEDES MOVER
		mlx_clear_window(game->window.mlx, game->window.win);
		
		//MOVEMOS EL PERSONAJE
		game->map.grid[y][x] = 'P';
		
		//LIMPIAMOS LA POSICION ANTIGUA
		game->map.grid[game->player.y_pos][game->player.x_pos] = '0';
		
		//ACTUALIZAMOS LA POSICION DEL PERSONAJE
		game->player.y_pos = y;
		game->player.x_pos = x;
		
		//ACTUALIZAMOS LOS PASOS DADOS
		game->steps++;
		
		ft_printf("NUMERO DE MOVIMIENTOS DADOS : %i\n", game->steps);
		return (1);
	}
	//NO TE PUEDES MOVER
	return (0);
}
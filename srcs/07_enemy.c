/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:56 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/02 01:56:01 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Function that counts the enemy nbr on the map.
int	ft_enemy_nbr(t_game *game)
{
	int		y;
	int		x;
	int		count;

	y = 0;
	count = 0;
	game->enemy_nbr = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'B')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

//Function that gives a direction to the enemy.
void	ft_select_movement(t_game game, int y, int x, int direction, int enemy_nbr)
{
	if (direction == 0)
	{
		game.enemy[enemy_nbr].skin = 2;
		ft_move_enemy(&game, (t_position){x, y - 1}, (t_position){x, y}, enemy_nbr);		
	}
	else if (direction == 1)
	{
		game.enemy[enemy_nbr].skin = 3;
		ft_move_enemy(&game, (t_position){x, y + 1}, (t_position){x, y}, enemy_nbr);		
	}
	else if (direction == 2)
	{
		game.enemy[enemy_nbr].skin = 5;
		ft_move_enemy(&game, (t_position){x + 1, y}, (t_position){x, y}, enemy_nbr);		
	}
	else if (direction == 3)
	{
		game.enemy[enemy_nbr].skin = 4;
		ft_move_enemy(&game, (t_position){x - 1, y}, (t_position){x, y}, enemy_nbr);		
	}
	else
		return ;
}

//Return a 'random' number between 0 and 3.
int	ft_rand(void)
{
	static unsigned int	seed;

	if (!seed)
		seed = getpid();
	seed = seed * 1103515245 + 12345 * getpid();
	return ((seed / 65536) % 4);
}

//This functions controls the enemies movements.
void	ft_randomize(t_game *game)
{
	static int	speed;
	int			i;
	int			y;
	char		**grid;
	int			x;

	speed++;
	if (speed == SPEED)
	{
		ft_found_enemy(game);
		i = 0;
		grid = game->map.grid;
		y = 0;
		while (i < game->enemy_nbr)
		{
			ft_select_movement(*game, game->enemy[i].position.y, \
			game->enemy[i].position.x, ft_rand(), i);
			i++;
		}
		speed = 0;
	}
}

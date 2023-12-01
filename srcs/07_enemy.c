/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:56 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/01 22:25:24 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Function that counts the enemy nbr on the map.
void	ft_enemy_nbr(t_game *game)
{
	int		y;
	int		x;
	t_enemy	*enemy;

	y = 0;
	game->enemy_nbr = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'B')
				game->enemy_nbr++;
			x++;
		}
		y++;
	}
}

//Function that founds the enemy on the map and creates the enemy struct.
void	ft_found_enemy(t_game *game)
{
	int		y;
	int		x;
	int		i;
	t_enemy	*enemy;

	y = 0;
	i = 0;
	ft_enemy_nbr(game);
	enemy = (t_enemy *)malloc(sizeof(t_enemy) * (game->enemy_nbr));
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'B')
			{
				enemy[i].position.x = x;
				enemy[i].position.y = y;
				enemy[i].skin = 0;
				i++;
			}
			x++;
		}
		y++;
	}
	game->enemy = enemy;
}

//Function that gives a direction to the enemy.
void	ft_select_movement(t_game game, int y, int x, int direction)
{
	if (direction == 0)
	{
		ft_move_enemy(&game, x, (y - 1), (t_position){x, y});
	}
	else if (direction == 1)
	{
		ft_move_enemy(&game, x, (y + 1), (t_position){x, y});
	}
	else if (direction == 2)
	{
		ft_move_enemy(&game, (x + 1), y, (t_position){x, y});
	}
	else if (direction == 3)
	{
		ft_move_enemy(&game, (x - 1), y, (t_position){x, y});
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
			game->enemy[i].position.x, ft_rand());
			i++;
		}
		speed = 0;
	}
}

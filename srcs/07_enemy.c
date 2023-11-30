/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:56 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 13:28:45 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_found_enemy(t_game *game)
{
	int		y;
	int		x;
	int		i;
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
	enemy = (t_enemy *)malloc(sizeof(t_enemy) * (game->enemy_nbr));
	i = 0;
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'B')
			{
				enemy[i].position.x = x;
				enemy[i].position.y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	game->enemy = enemy;
}

void	ft_select_movement(t_game game, int y, int x, int direction)
{
	if (direction == 0)
	{
		ft_move_enemy(&game, x, (y - 1), x, y);
	}
	else if (direction == 1)
	{
		ft_move_enemy(&game, x, (y + 1), x, y);
	}
	else if (direction == 2)
	{
		ft_move_enemy(&game, (x + 1), y, x, y);
	}
	else if (direction == 3)
	{
		ft_move_enemy(&game, (x - 1), y, x, y);
	}
	else
		return ;
}

int	ft_rand(void)
{
	static unsigned int	seed;

	if (!seed)
		seed = getpid();
	seed = seed * 1103515245 + 12345 * getpid();
	return ((seed / 65536) % 4);
}

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

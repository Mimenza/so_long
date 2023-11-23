/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:56 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/23 13:32:18 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

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
}

unsigned int	custom_random(void)
{
	static unsigned int	seed;

	seed = 0;
	seed = (seed * 1103515245 + 12345) & 0xFFFFFFFF;
	return ((seed >> 16) & 0x03);
}

void	ft_randomize(t_game *game)
{
	int		enemy_n;
	int		i;
	int		y;
	char	**grid;
	int		x;

	grid = game->map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'B')
			{
				ft_select_movement(*game, y, x, rand() % 3);
			}
			x++;
		}
		y++;
	}
}

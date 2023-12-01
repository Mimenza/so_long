/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:52:42 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/01 20:52:38 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"
//Checks if the str has smth apart from c 
int	ft_strcustom(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

//Check if the map is within walls
int	ft_map_wall(char **grid, int w, int h)
{
	int	i;
	int	ok;

	ok = 0;
	i = 0;
	ft_printf("CHECKING THE MAP LIMMITS....");
	while (grid[i])
	{
		if (i == 0 || i == (h - 1))
			ok = ft_strcustom(grid[i], '1');
		else
		{
			if ((grid[i][0] != '1') || (grid[i][w - 1] != '1'))
				ok = 0;
		}
		i++;
		if (ok == 0)
		{
			ft_print_error(5);
			return (0);
		}
	}
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	return (1);
}

//Locate a player on the map
t_player	ft_locate_player(t_map map)
{
	t_player	player;
	char		**grid;
	int			x;
	int			y;

	grid = map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
				player.pos.x = x;
				player.pos.y = y;
				player.framerate = ANIMATION_FRAMES;
				player.skin = 7;
				return (player);
			}
			x++;
		}
		y++;
	}
	return (player);
}

//Locate a exit on the map
t_exit	ft_locate_exit(t_map map)
{
	t_exit	exit;
	char	**grid;
	int		x;
	int		y;

	grid = map.grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'E')
			{
				exit.position.x = x;
				exit.position.y = y;
				return (exit);
			}
			x++;
		}
		y++;
	}
	return (exit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:10:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 15:11:09 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int ft_check_above(int x, int y, char **grid)
{
	if (grid[y][x - 1] && ((grid[y][x - 1] == '0') || (grid[y][x - 1] == 'C') || (grid[y][x - 1] == 'E')))
	{
		grid[y][x - 1] = 'P';
		return (1);
	}
	return (0);
}

int ft_check_below(int x, int y, char **grid)
{

	if (grid[y][x + 1] && ((grid[y][x + 1] == '0') || (grid[y][x + 1] == 'C') || (grid[y][x + 1] == 'E')))
	{
		grid[y][x + 1]= 'P';
		return (1);
	}
	return (0);
}

int ft_check_right(int x, int y, char **grid)
{
	if (grid[y + 1][x] && ((grid[y + 1][x] == '0') || (grid[y + 1][x] == 'C') || (grid[y + 1][x] == 'E')))
	{
		grid[y + 1][x]= 'P';
		return (1);
	}
	return (0);
	}

int ft_check_left(int x, int y, char **grid)
{
	if (grid[y - 1][x] && ((grid[y - 1][x] == '0') || (grid[y - 1][x] == 'C') || (grid[y - 1][x] == 'E')))
	{
		grid[y - 1][x] = 'P';
		return (1);
	}
	return (0);
}

//looks for a player with an new moveable area
int ft_expandable(char **grid, t_player *player)
{
	int		x;
	int		y;
	int		a;
	int		b;
	int		r;
	int		l;

	y = 0;

	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
				//WE HAVE FOUND A PLAYER
				a = ft_check_above(x, y, grid);
				b = ft_check_below(x, y, grid);
				r = ft_check_right(x, y, grid);
				l = ft_check_left(x, y, grid);

				if ( a == 1 || b == 1|| r == 1|| l == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int ft_reachable(char ** grid, t_size *size)
{
	int			x;
	int			y;
	t_player	player;
	int			expandable;
	char		**p_grid;

	expandable = 1;
	p_grid = ft_create_doubleptr(*size);	
	ft_copy_doubleptr(grid, p_grid, *size);
	
	while (expandable == 1)
		expandable = ft_expandable(p_grid, &player);
		
	if (1 == ft_check_items_reach(p_grid, grid))
	{
		ft_free_doubleptr(p_grid);
		return (1);
	}
	ft_printf("\033[1;31m [KO] \033[0m\n--> THE MAP IS NOT SOLVEABLE\n");
	ft_free_doubleptr(p_grid);
	return (0);
}

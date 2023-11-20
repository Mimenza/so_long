/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:10:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/20 12:23:19 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//looks for a player with an new moveable area
int	ft_expandable(char **grid, t_player *player)
{
	int			x;
	int			y;
	t_coords	coords;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
				coords.a = ft_check_above(x, y, grid);
				coords.b = ft_check_below(x, y, grid);
				coords.r = ft_check_right(x, y, grid);
				coords.l = ft_check_left(x, y, grid);
				if (coords.a == 1 || coords.b == 1 \
				|| coords.r == 1 || coords.l == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_reachable(char **grid, t_size *size)
{
	t_player	player;
	int			expandable;
	char		**p_grid;

	expandable = 1;
	ft_printf("CHECKING IF THE MAP IS DO-ABLE...");
	p_grid = ft_create_doubleptr(*size);
	ft_copy_doubleptr(grid, p_grid, *size);
	while (expandable == 1)
		expandable = ft_expandable(p_grid, &player);
	if (1 == ft_check_items_reach(p_grid, grid))
	{
		ft_free_doubleptr(p_grid);
		ft_printf("\033[0;32m [OK] \033[0m\n\n");
		return (1);
	}
	ft_printf("\033[1;31m [KO] \033[0m\n--> THE MAP IS NOT SOLVEABLE\n");
	ft_free_doubleptr(p_grid);
	return (0);
}

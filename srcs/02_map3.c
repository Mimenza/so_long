/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:10:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/07 10:06:07 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Aux function which checks if the map is doable
static int	ft_expandable(char **grid, t_player *player)
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

//Main function which checks if the map is doable
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
	ft_free_doubleptr(p_grid);
	ft_print_error(6);
	return (0);
}

//Counts the entity number
int	ft_count_item(char c, int *player, int *exit, int *coll)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != 49 && c != 48 && c != 'B')
	{
		ft_print_error(7);
		return (0);
	}
	if (c == 'P')
		*player += 1;
	else if (c == 'E')
		*exit += 1;
	else if (c == 'C')
		*coll += 1;
	return (1);
}

//Check the  entity number
int	ft_check_item(char c, int *player, int *exit, int *coll)
{
	if (*player != 1)
		ft_print_error(8);
	if (*exit != 1)
		ft_print_error(9);
	if (*coll < 1)
		ft_print_error(10);
	if ((*player == 1) && (*exit == 1) && (*coll >= 1))
		return (1);
	return (0);
}

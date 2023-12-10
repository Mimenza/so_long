/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:47:37 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/10 19:21:47 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

//This funtions compares the og grid with the expanded
//grid in order to find if the map is doable.
int	ft_check_items_reach(char **grid, char **og_grid)
{
	int		x;
	int		y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E' || grid[y][x] == 'B')
			{
				if (og_grid[y][x] != 'P')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

//This function prints the grid on the console.
void	ft_print_grid(char **grid)
{
	int		x;
	int		y;

	y = 0;
	ft_printf("\n");
	while (grid[y])
	{
		ft_printf("%s\n", grid[y]);
		y++;
	}
}

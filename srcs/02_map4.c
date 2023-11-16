/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:47:37 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/16 16:53:38 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

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
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
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

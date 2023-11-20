/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:23:06 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/20 13:40:57 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_check_above(int x, int y, char **grid)
{
	if (grid[y][x - 1] && ((grid[y][x - 1] == '0') \
	|| (grid[y][x - 1] == 'C') || (grid[y][x - 1] == 'E')))
	{
		grid[y][x - 1] = 'P';
		return (1);
	}
	return (0);
}

int	ft_check_below(int x, int y, char **grid)
{
	if (grid[y][x + 1] && ((grid[y][x + 1] == '0') \
	|| (grid[y][x + 1] == 'C') || (grid[y][x + 1] == 'E')))
	{
		grid[y][x + 1] = 'P';
		return (1);
	}
	return (0);
}

int	ft_check_right(int x, int y, char **grid)
{
	if (grid[y + 1][x] && ((grid[y + 1][x] == '0') \
	|| (grid[y + 1][x] == 'C') || (grid[y + 1][x] == 'E')))
	{
		grid[y + 1][x] = 'P';
		return (1);
	}
	return (0);
}

int	ft_check_left(int x, int y, char **grid)
{
	if (grid[y - 1][x] && ((grid[y - 1][x] == '0') \
	|| (grid[y - 1][x] == 'C') || (grid[y - 1][x] == 'E')))
	{
		grid[y - 1][x] = 'P';
		return (1);
	}
	return (0);
}

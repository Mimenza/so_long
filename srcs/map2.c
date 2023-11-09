/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:52:42 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 15:45:21 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_strcustom(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int ft_map_wall(char **grid, int w, int h)
{
	int i;
	int	ok;

	ok = 0;
	i = 0;
	while (grid[i])
	{
		if (i == 0 || i == h)
		{
			//primera y ultima linea
			ok = ft_strcustom(grid[i], 1);
		}
		else
		{
			//lineas intermedias
			if ((grid[i][0] != 1) || (grid[i][w] != 1))
				ok = 0;
		}
		i++;
	}
	if(ok == 0)
		ft_printf("MAP MUST BE WITHIN WALL");
	return (ok);
}

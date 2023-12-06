/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/06 09:41:55 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

// Function to create and validate the grid
char	**ft_create_and_validate_grid(char *strmap, t_size **size, int *n_coll)
{
	char	**grid;

	if (ft_create_grid(strmap, &grid) == 0)
		return (NULL);
	if (ft_map_size(grid, size) == 0)
	{
		ft_free_doubleptr(grid);
		return (NULL);
	}
	ft_printf("CHECKING THE MAP COLLECTABLES...");
	*n_coll = ft_map_coll(grid);
	if (*n_coll == 0 || !ft_map_wall(grid, (*size)->w, \
	(*size)->h) || ft_reachable(grid, *size) == 0)
	{
		ft_free_doubleptr(grid);
		free(*size);
		return (NULL);
	}
	return (grid);
}

// Main function which creates the map struct
t_map	ft_create_map(char *strmap)
{
	t_map	map;
	t_size	*size;
	char	**grid;
	int		n_coll;

	map.created = 0;
	grid = ft_create_and_validate_grid(strmap, &size, &n_coll);
	if (grid == NULL)
		return (map);
	map.grid = grid;
	map.size = size;
	map.n_coll = n_coll;
	map.created = 1;
	return (map);
}

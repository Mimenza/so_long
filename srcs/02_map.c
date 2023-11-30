/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/28 13:07:47 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_map	ft_create_map(char *strmap)
{
	t_map	map;
	t_size	*size;
	char	**grid;
	int		n_coll;

	map.created = 0;
	if (ft_create_grid(strmap, &grid) == 0)
		return (map);
	if (ft_map_size(grid, &size) == 0)
		return (map);
	ft_printf("CHECKING THE MAP COLLECTABLES...");
	n_coll = ft_map_coll(grid);
	if (n_coll == 0)
		return (map);
	if (!ft_map_wall(grid, size->w, size->h))
		return (map);
	if (ft_reachable(grid, size) == 0)
		return (map);
	map.grid = grid;
	map.size = size;
	map.n_coll = n_coll;
	map.created = 1;
	return (map);
}

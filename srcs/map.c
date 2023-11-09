/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 15:38:47 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_map	*ft_create_map(char *strmap)
{
	t_map	*map;
	
	t_size	*size;
	char	**grid;
	int		n_coll;

	grid = ft_create_grid(strmap);
	if (grid == NULL)
		return (NULL);
	size = ft_map_size(grid);
	if(size->h == 0 || size->w == 0)
		return(NULL);
	n_coll = ft_map_coll(grid);
	if(n_coll == 0)
		return(NULL);
	if(!ft_map_wall(grid, size->w, size->h))
		return(NULL);
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
		
	map->grid = grid;
	map->size = size;
	map->n_coll = n_coll;
	
	return (map);
}
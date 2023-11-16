/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/16 16:22:33 by emimenza         ###   ########.fr       */
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
	//read the file and create a double pointer with the map data
	ft_printf("CREATING THE GRID....");
	if (ft_create_grid(strmap, &grid) == 0)
		return (map);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	
	//check the map size and stored || null if the map is not rectangular
	ft_printf("CHECKING THE MAP SIZE...");
	if (ft_map_size(grid, &size) == 0)
		return (map);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	
	//save the map collectables number || null if the map has no collectables or more than either 1 player or exit
	ft_printf("CHECKING THE MAP COLLECTABLES...");
	n_coll = ft_map_coll(grid);
	if (n_coll == 0)
		return (map);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	
	//check if the map is surrounded by walls (1) || null if not
	ft_printf("CHECKING THE MAP LIMMITS....");
	if(!ft_map_wall(grid, size->w, size->h))
		return (map);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	
	//check if all the coins and exit are reachable || null if not
	ft_printf("CHECKING IF THE MAP IS DO-ABLE...");
	if (ft_reachable(grid, size) == 0)
		return (map);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");

	// map = (t_map *)malloc(sizeof(t_map));
	// if (!map)
	// 	return (NULL);
	map.grid = grid;
	map.size = size;
	map.n_coll = n_coll;
	map.created = 1;
	
	return (map);
}


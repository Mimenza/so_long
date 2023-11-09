/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:11 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 17:44:25 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_map	*ft_create_map(char *strmap)
{
	t_map	*map;	
	t_size	*size;
	char	**grid;
	int		n_coll;

	//read the file and create a double pointer with the map data
	ft_printf("CREATING THE GRID....\n");
	grid = ft_create_grid(strmap);
	if (grid == NULL)
		return (NULL);
	ft_printf("GRID CREATED\n");
	
	//check the map size and stored || null if the map is not rectangular
	ft_printf("CHECKING THE MAP SIZE...\n");
	size = ft_map_size(grid);
	if(size->h == 0 || size->w == 0)
		return(NULL);
	ft_printf("SIZE IS CORRECT\n");
	
	//save the map collectables number || null if the map has no collectables or more than either 1 player or exit
	ft_printf("CHECKING THE MAP COLLECTABLES...\n");
	n_coll = ft_map_coll(grid);
	if(n_coll == 0)
		return(NULL);
	ft_printf("COLLECTABLES FOUND\n");
	
	//check if the map is surrounded by walls (1) || null if not 
	ft_printf("CHECKING THE MAP LIMMITS...\n");
	if(!ft_map_wall(grid, size->w, size->h))
		return(NULL);
	ft_printf("LIMITS CHECKED\n");
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
		
	map->grid = grid;
	map->size = size;
	map->n_coll = n_coll;
	
	return (map);
}

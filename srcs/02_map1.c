/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:27:12 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 10:39:28 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Read the file and return the line with all the content
char *ft_read_file(char *strmap)
{
	char	*path;
	int		fdmap;
	char	*t_line;
	char	*line;

	path = ft_strjoin("./maps/", strmap);
	fdmap = open(path, O_RDONLY);
	free(path);
	if (fdmap == -1)
	{
		ft_printf("\033[1;31m [KO] \033[0m\n--> ERROR READING THE FILE\n");
		return (NULL);
	}
	t_line = "";
	line = "";
	while (line)
	{
		line = get_next_line(fdmap);
		if (line != NULL)
		{
			t_line = ft_strjoin(t_line, line);
			free(line);
		}
	}
	close(fdmap);
	if (t_line == NULL)
	{
		free(t_line);
		return (NULL);
	}
	return (t_line);
}

//Create the map grid 
char **ft_create_grid(char *strmap)
{
	char	*file_content;
	char	**grid;

	file_content = ft_read_file(strmap);
	if (file_content == NULL)
	{
		ft_printf("\033[1;31m [KO] \033[0m\n--> ERROR\n");
		return (NULL);
	}
	grid = ft_split(file_content, '\n');
	free(file_content);
	if (grid == NULL)
	{
		ft_printf("\033[1;31m [KO] \033[0m\n--> ERROR CREATING THE GRID\n");
		return (NULL);
	}
	return (grid);
}

//Checks the map size and stores the info
t_size	*ft_map_size(char **grid)
{
	int		x;
	int		y;
	int		t_x;
	t_size	*size;

	y = 0;
	t_x = 0 ;
	size = (t_size *)malloc(sizeof(t_size));
	if (!size)
		return (NULL);
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			x++;
		if(t_x == 0)
			t_x = x;
		if (t_x != 0 && t_x != x)
			{
				ft_printf("\033[1;31m [KO] \033[0m\n--> WRONG MAP SIZE!\n");
				free(size);
				return(size);
			}
		y++;
	}
	size->h = y;
	size->w = x;
	return(size);
}

//Check the map collectables and player/exit
int	ft_map_coll(char **grid)
{
	int		x;
	int		y;
	int		player;
	int		coll;
	int		exit;

	y = 0;
	player = 0;
	exit  = 0;
	coll = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (0 == ft_check_item(grid[y][x], &player, &exit, &coll, 0))
				return (0);
			x++;
		}
		y++;
	}	
	if (ft_check_item(0, &player, &exit, &coll, 1) == 0)
		return (0);
	
	return (coll);
}

//Counts the entity number
int	ft_check_item(char c, int *player, int *exit, int *coll, int mode)
{
	if (mode == 0)
	{
		if (c != 'P' && c != 'E' && c != 'C' && c != 49 && c != 48)
		{
			ft_printf("\033[1;31m [KO] \033[0m\n--> FOUND A NON VALID CHAR\n");
			return(0);
		}
		
		if (c == 'P')
			*player += 1;
		else if (c == 'E')
			*exit += 1;
		else if (c == 'C')
			*coll += 1;
		return (1);
	}
	if (mode == 1)
	{
		if (*player != 1)
			ft_printf("\033[1;31m [KO] \033[0m\n--> THERE MUST BE ONLY 1 PLAYER\n");
		if (*exit != 1)
			ft_printf("\033[1;31m [KO] \033[0m\n--> THERE MUST BE ONLY 1 EXIT\n");
		if (*coll < 1)
			ft_printf("\033[1;31m [KO] \033[0m\n--> THERE MUST BE AT LEAST 1 COLLECTABLE\n");	
		if ((*player == 1) || (*exit == 1) || (*coll >= 1))
			return (1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:27:12 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/11 08:25:21 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//Read the file and return the line with all the content
static char	*ft_read_file(char *strmap, char *t_line)
{
	char	*path;
	int		fdmap;
	char	*line;
	char	*tmp;

	path = ft_strjoin("./maps/", strmap);
	fdmap = open(path, O_RDONLY);
	free(path);
	if (fdmap == -1)
		return (NULL);
	while (line)
	{
		line = get_next_line(fdmap);
		if (line != NULL)
		{
			tmp = ft_strdup(t_line);
			free(t_line);
			t_line = ft_strjoin(tmp, line);
			free(line);
			free(tmp);
		}
	}
	close(fdmap);
	return (t_line);
}

//Create the map grid 
int	ft_create_grid(char *strmap, char ***grid)
{
	char	*file_content;

	ft_printf("CREATING THE GRID....");
	file_content = ft_strdup("");
	file_content = ft_read_file(strmap, file_content);
	if (file_content == NULL)
	{
		ft_print_error(2);
		return (0);
	}
	*grid = ft_split(file_content, '\n');
	free(file_content);
	if (*grid == NULL)
	{
		ft_print_error(3);
		return (0);
	}
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	return (1);
}

//Checks the map size and stores the info
int	ft_map_size(char **grid, t_size **size)
{
	int		x;
	int		y;
	int		t_x;

	y = 0;
	t_x = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
			x++;
		if (t_x == 0)
			t_x = x;
		if (t_x != 0 && t_x != x)
		{
			return (0);
		}
		y++;
	}
	(*size) = (t_size *)malloc(sizeof(t_size));
	if ((*size) == NULL)
		return (0);
	(*size)->w = x;
	(*size)->h = y;
	return (1);
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
	exit = 0;
	coll = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (0 == ft_count_item(grid[y][x], &player, &exit, &coll))
				return (0);
			x++;
		}
		y++;
	}
	if (ft_check_item(0, &player, &exit, &coll) == 0)
		return (0);
	ft_printf("\033[0;32m [OK] \033[0m\n\n");
	return (coll);
}

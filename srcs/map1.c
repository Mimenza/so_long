/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:27:12 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/08 13:39:19 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char **ft_create_grid(char *strmap)
{
	char	**grid;
	int		fdmap;
	char	*path;
	char	*tmp;
	char 	*t_line;

	tmp = "a";
	t_line = "";
	path = "./maps/";
	//ft_printf("%s", ft_strjoin(path, strmap));
	fdmap = open(ft_strjoin(path, strmap), O_RDONLY);
	while(tmp)
	{
		tmp = get_next_line(fdmap);
		if (tmp == NULL)
			break;
		t_line = ft_strjoin(t_line, tmp);
		free(tmp);
	}
	close(fdmap);
	grid = ft_split(t_line, '\n');
	return (grid);
}
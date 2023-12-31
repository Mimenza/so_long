/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:46 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/10 18:57:03 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_free_map_size(t_game game)
{
	if (game.map.size->h != 0 && game.map.size->h != 0)
		free(game.map.size);
}

void	ft_free_win_size(t_game game)
{
	if (game.window.size->h != 0 && game.window.size->w != 0)
		free(game.window.size);
}

//This functions frees a double ptr.
void	ft_free_doubleptr(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

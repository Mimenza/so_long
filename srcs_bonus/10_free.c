/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:54:46 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/15 08:26:13 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:20:58 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/10 11:25:44 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	**ft_create_doubleptr(t_size size)
{
	char	**ptr;
	int		i;

	i = 0;
	
	// Crear una nueva matriz para la copia
	ptr = (char **)malloc((size.h + 1) * sizeof(char*));
	while (i < (size.h))
	{
		ptr[i] = (char*)malloc((size.w + 1) * sizeof(char));
		i++;
	}
	return (ptr);
}

void	ft_copy_doubleptr(char **grid, char **p_grid, t_size size)
{
	int	i;

	i = 0;
	while (i < (size.h))
	{
		ft_memcpy(p_grid[i], grid[i], (size.w) * sizeof(int));
		i++;
	}
}


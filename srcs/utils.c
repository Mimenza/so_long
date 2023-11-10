/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:20:58 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/10 09:45:03 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	**ft_create_doubleptr(t_size size)
{
	char	**ptr;
	int		i;

	i = 0;

	// Crear una nueva matriz para la copia
	ptr = (char **)malloc((size.h) * sizeof(char*));
	while (i < (size.w - 1))
	{
		ptr[i] = (char*)malloc((size.w) * sizeof(char));
		i++;
	}
	return (ptr);
}

void	ft_copy_doubleptr(char **grid, char **og_grid, t_size size)
{
	int	i;

	i = 0;
	while (i < (size.h))
	{
		ft_memcpy(og_grid[i], grid[i], (size.w) * sizeof(int));
		i++;
	}
}

void ft_print_grid(char **grid)
{
	printf("%s\n", grid[0]);
	printf("%s\n", grid[1]);
	printf("%s\n", grid[2]);
	printf("%s\n", grid[3]);
	printf("%s\n", grid[4]);
	printf("\n\n\n\n");
}

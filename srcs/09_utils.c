/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:20:58 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 17:01:07 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//This functions frees a double ptr.
void	ft_free_doubleptr(char **grid)
{
	int	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

//This function creates a double ptr.
char	**ft_create_doubleptr(t_size size)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = (char **)malloc((size.h + 1) * sizeof(char *));
	if (ptr == NULL)
		return (ptr);
	return (ptr);
}

//This function copies a double ptr.
void	ft_copy_doubleptr(char **grid, char **p_grid, t_size size)
{
	int	i;

	i = 0;
	while (i <= (size.h - 1))
	{
		p_grid[i] = ft_strdup(grid[i]);
		i++;
	}
	p_grid[i] = NULL;
}


void print_game_name()
{
ft_printf("\n");
ft_printf("   ███████╗ ██████╗             ██╗      ██████╗ ███╗   ██╗ ██████╗ \n");
ft_printf("   ██╔════╝██╔═══██╗            ██║     ██╔═══██╗████╗  ██║██╔════╝ \n");
ft_printf("   ███████╗██║   ██║            ██║     ██║   ██║██╔██╗ ██║██║  ███╗\n");
ft_printf("   ╚════██║██║   ██║            ██║     ██║   ██║██║╚██╗██║██║   ██║\n");
ft_printf("   ███████║╚██████╔╝███████████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝\n");
ft_printf("   ╚══════╝ ╚═════╝ ╚══════════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n");
}

void print_game_over()
{
	ft_printf("\n");
	ft_printf("    ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ ██╗\n");
	ft_printf("   ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗██║\n");
	ft_printf("   ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝██║\n");
	ft_printf("   ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗╚═╝\n");
	ft_printf("   ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║██╗\n");
	ft_printf("    ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝╚═╝\n");
}


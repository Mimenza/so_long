/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:20:58 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/20 12:36:11 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_free_doubleptr(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

char	**ft_create_doubleptr(t_size size)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = (char **)malloc((size.h + 1) * sizeof(char *));
	if (ptr == NULL)
		return (ptr);
	while (i < (size.h))
	{
		ptr[i] = (char *)malloc((size.w + 1) * sizeof(char));
		if (ptr[i] == NULL)
		{
			ft_free_doubleptr(ptr);
			return (ptr);
		}
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
		ft_memcpy(p_grid[i], grid[i], (size.w) * sizeof(char));
		i++;
	}
}

void	imprimir_patron(void)
{
	ft_printf("\n");
	ft_printf("  ██████  ▒█████   ██▓     ▒█████   ███▄    █   ▄████ \n");
	ft_printf("▒██    ▒ ▒██▒  ██▒▓██▒    ▒██▒  ██▒ ██ ▀█   █  ██▒ ▀█▒\n");
	ft_printf("░ ▓██▄   ▒██░  ██▒▒██░    ▒██░  ██▒▓██  ▀█ ██▒▒██░▄▄▄░\n");
	ft_printf("  ▒   ██▒▒██   ██░▒██░    ▒██   ██░▓██▒  ▐▌██▒░▓█  ██▓\n");
	ft_printf("▒██████▒▒░ ████▓▒░░██████▒░ ████▓▒░▒██░   ▓██░░▒▓███▀▒\n");
	ft_printf("▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ░ ▒░▓  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ░▒   ▒ \n");
	ft_printf("░ ░▒  ░ ░  ░ ▒ ▒░ ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░░   ░ ▒░  ░   ░ \n");
	ft_printf("░  ░  ░  ░ ░ ░ ▒    ░ ░   ░ ░ ░ ▒     ░   ░ ░ ░ ░   ░ \n");
	ft_printf("      ░      ░ ░      ░  ░    ░ ░           ░       ░ \n");
	ft_printf("\n");
}

void	ft_print_info(t_game game)
{
	mlx_string_put(game.window.mlx, game.window.win, 5, 10, 0x00000000, \
	"MOVES");
	mlx_string_put(game.window.mlx, game.window.win, 5, 20, 0x00000000, \
	ft_itoa(game.steps));
	mlx_string_put(game.window.mlx, game.window.win, 5, 30, 0x00000000, \
	"COLLECTABLES:");
	mlx_string_put(game.window.mlx, game.window.win, 5, 40, 0x00000000, \
	ft_itoa(game.coll));
	mlx_string_put(game.window.mlx, game.window.win, 10, 40, 0x00000000, \
	"/");
	mlx_string_put(game.window.mlx, game.window.win, 15, 40, 0x00000000, \
	ft_itoa(game.map.n_coll));
}

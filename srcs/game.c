/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/11 19:43:04 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"


void ft_start_program(t_game game)
{
	// mlx function that initialize the mlx and returns a pointer to it.
	game.window.mlx = mlx_init();
	
	if (!game.window.mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		exit(EXIT_FAILURE);
	}
	
	// Open a window (window.c whitin this project)
	game.window = ft_new_window(game.window.mlx, 1920, 1080, "JUEGAZO");

	// mlx constant loop that keeps the detects the events
	mlx_loop(game.window.mlx);
}

t_game	ft_create_game(char *strmap, t_game *game)
{	
	game->map = ft_create_map(strmap);
	if (game->map == NULL)
		return(*game);
	game->player = ft_locate_player(game->map);
	game->exit = ft_locate_exit(game->map);
	game->coll = 0; 
	game->steps	= 0;
	ft_start_program(*game);
	return (*game);
}

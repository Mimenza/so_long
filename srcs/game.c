/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/12 00:49:02 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"


void ft_start_program(t_game game)
{
	// mlx function that initialize the mlx and returns a pointer to it.
	void	*mlx;

	mlx = mlx_init();
	game.window.mlx = mlx;	
	if (!game.window.mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		exit(EXIT_FAILURE);
	}	
	// Open a window (window.c whitin this project)
	t_window win = ft_new_window(game.window.mlx, 1920, 1080, "JUEGAZO");
	game.window = win;
	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(game.window.win, *ft_input, &game);
	// hook a function to the loop (it would be called each frame)
	mlx_loop_hook(game.window.mlx, *ft_update, &game);
	
	// mlx constant loop that keeps the detects the events
	mlx_loop(mlx);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 15:53:39 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_load(t_game *game, char *path, int i)
{
	int		pxx;
	int		h;
	int		w;

	pxx = PX;
	game->window.img[i] = mlx_xpm_file_to_image(game->window.mlx, path, &w, &h);
	if (game->window.img[i] == NULL)
	{
		printf("ERROR\n");
		return ;
	}
}

void	ft_load_imgs(t_game *game)
{
	char	files[IMG_COUNT][40];
	int		i;

	ft_strlcpy(files[0], FLOOR, 39);
	ft_strlcpy(files[1], WALL, 39);
	ft_strlcpy(files[2], COLL, 39);
	ft_strlcpy(files[3], PLAYER_D, 39);
	ft_strlcpy(files[4], PLAYER_U, 39);
	ft_strlcpy(files[5], PLAYER_L, 39);
	ft_strlcpy(files[6], PLAYER_R, 39);
	ft_strlcpy(files[7], EXIT_C, 39);
	ft_strlcpy(files[8], EXIT_O, 39);
	ft_strlcpy(files[9], COLL_A_1, 39);
	ft_strlcpy(files[10], COLL_A_2, 39);
	ft_strlcpy(files[11], COLL_A_3, 39);
	ft_strlcpy(files[12], COLL_A_4, 39);
	ft_strlcpy(files[13], COLL_A_5, 39);
	ft_strlcpy(files[14], COLL_A_6, 39);
	ft_strlcpy(files[15], COLL_A_7, 39);
	ft_strlcpy(files[16], COLL_A_8, 39);
	ft_strlcpy(files[17], ENEMY, 39);
	i = -1;

	while (++i < IMG_COUNT)
		ft_load(game, files[i], i);
}

void ft_start_game(t_game game)
{
	//mlx function that initialize the mlx and returns a pointer to it.
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("Error: mlx_init() failed\n");
		exit(EXIT_FAILURE);
	}
	
	game.window.mlx = mlx;
	// Open a window (window.c whitin this project)
	t_window win = ft_new_window(game.window.mlx, game.map.size->w * 48, game.map.size->h * 48, "SO_LONG");
	game.window = win;
	
	// Load the texture imgs
	ft_load_imgs(&game);

	// Print the map
	ft_print_map(&game);
	
	// hook the input() (hooks.c) function to the the key pressed event
	mlx_key_hook(game.window.win, *ft_input, &game);

	// hook a function to the loop (it would be called each frame)
	//mlx_loop_hook(game.window.mlx, *ft_update, &game);

	// mlx constant loop that keeps the detects the events
	mlx_loop(mlx);
}

t_game	ft_create_game(char *strmap, t_game *game)
{
	game->map = ft_create_map(strmap);
	if (!game->map.grid)
	{
		free(game->map.size);
		ft_free_doubleptr(game->map.grid);
		return(*game);
	}
	game->player = ft_locate_player(game->map);
	game->exit = ft_locate_exit(game->map);
	game->coll = 0; 
	game->steps	= 0;
	
	ft_start_game(*game);
	return (*game);
}

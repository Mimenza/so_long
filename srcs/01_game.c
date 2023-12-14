/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/14 09:52:08 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//This functions loads the imgs.
static void	ft_load(t_game *game, char *path, int i)
{
	int		h;
	int		w;

	game->window.img[i] = mlx_xpm_file_to_image(game->window.mlx, path, &w, &h);
	if (game->window.img[i] == NULL)
	{
		printf("ERROR LOADING IMGS%i\n", i);
		return ;
	}
}

static void	ft_cpy_imgs(char files[IMG_COUNT][42], t_game *game)
{
	int	i;

	i = IMG_COUNT - 1;
	while (i >= 0)
	{
		ft_load(game, files[i], i);
		i--;
	}
}

//This function loads the imgs path into the array.
static void	ft_load_imgs(t_game *game)
{
	char	files[IMG_COUNT][42];

	ft_strlcpy(files[0], FLOOR, 41);
	ft_strlcpy(files[1], WALL, 41);
	ft_strlcpy(files[2], ENEMY_D, 41);
	ft_strlcpy(files[3], PLAYER_D, 41);
	ft_strlcpy(files[4], EXIT_C, 41);
	ft_strlcpy(files[5], COIN_1, 41);
	ft_cpy_imgs(files, game);
}

//Main function which starts the game.
static void	ft_start_game(t_game game)
{
	void		*mlx;
	t_window	win;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_print_error(1);
		exit(EXIT_FAILURE);
	}
	win = ft_new_window(mlx, game.map.size->w * PX, \
	game.map.size->h * PX, "SO_LONG");
	game.window = win;
	ft_load_imgs(&game);
	ft_print_map(&game);
	mlx_key_hook(game.window.win, *ft_input, &game);
	mlx_loop(mlx);
}

//Main function which creates the game struct.
t_game	ft_create_game(char *strmap, t_game *game)
{
	t_map	map;

	map = ft_create_map(strmap);
	if (map.created == 0)
	{
		ft_free_map_size(*game);
		ft_free_win_size(*game);
		game->created = 0;
		return (*game);
	}
	game->map = map;
	game->p = ft_locate_player(game->map);
	game->exit = ft_locate_exit(game->map);
	game->coll = 0;
	game->steps = 0;
	game->created = 1;
	game->coll_skin = 0;
	ft_start_game(*game);
	return (*game);
}

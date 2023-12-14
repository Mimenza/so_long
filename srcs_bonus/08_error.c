/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:11:21 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/14 10:49:59 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long_bonus.h"

void	ft_print_error(int type)
{
	if (type == 0)
		ft_printf("\033[1;31m [KO] \033[0m \n Error\n WRONG FILE NAME  \n");
	else if (type == 1)
		ft_printf("\033[1;31m [KO] \033[0m\nError\n mlx_init() failed\n");
	else if (type == 2)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nERROR READING THE FILE\n");
	else if (type == 3)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nERROR CREATING THE GRID\n");
	else if (type == 4)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nWRONG MAP SIZE!\n");
	else if (type == 5)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nMAP MUST BE WITHIN WALL \n");
	else if (type == 6)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nTHE MAP IS NOT SOLVEABLE\n");
	else if (type == 7)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nFOUND A NON VALID CHAR\n");
	else if (type == 8)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nMUST BE ONLY 1 PLAYER\n");
	else if (type == 9)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nMUST BE ONLY 1 EXIT\n");
	else if (type == 10)
		ft_printf("\033[1;31m [KO] \033[0m\nError\nMUST BE MIN 1 COLL\n");
}

//Function that counts the enemy nbr on the map.
int	ft_enemy_nbr(t_game *game)
{
	int		y;
	int		x;
	int		count;

	y = 0;
	count = 0;
	game->enemy_nbr = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == 'B')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

//Function that gives a direction to the enemy.
void	ft_select_movement(t_game game, t_position pos, int dir, int e_nbr)
{
	if (dir == 0)
	{
		game.enemy[e_nbr].skin = 2;
		ft_move_enemy(&game, (t_position){pos.x, pos.y - 1}, \
		(t_position){pos.x, pos.y}, e_nbr);
	}
	else if (dir == 1)
	{
		game.enemy[e_nbr].skin = 3;
		ft_move_enemy(&game, (t_position){pos.x, pos.y + 1}, \
		(t_position){pos.x, pos.y}, e_nbr);
	}
	else if (dir == 2)
	{
		game.enemy[e_nbr].skin = 4;
		ft_move_enemy(&game, (t_position){pos.x - 1, pos.y}, \
		(t_position){pos.x, pos.y}, e_nbr);
	}
	else if (dir == 3)
	{
		game.enemy[e_nbr].skin = 5;
		ft_move_enemy(&game, (t_position){pos.x + 1, pos.y}, \
		(t_position){pos.x, pos.y}, e_nbr);
	}
	ft_print_map(&game);
}

//Return a 'random' number between 0 and 3.
int	ft_rand(void)
{
	static unsigned int	seed;

	if (!seed)
		seed = getpid();
	seed = seed * 1103515245 + 12345 * getpid();
	return ((seed / 65536) % 4);
}

//This functions controls the enemies movements.
void	ft_randomize(t_game *game)
{
	static int	speed;
	int			i;
	int			y;
	char		**grid;
	int			x;

	speed++;
	if (speed == SPEED)
	{
		ft_found_enemy(game);
		i = 0;
		grid = game->map.grid;
		y = 0;
		while (i < game->enemy_nbr)
		{
			ft_select_movement(*game, (t_position){game->enemy[i].position.x, \
			game->enemy[i].position.y}, ft_rand(), i);
			i++;
		}
		speed = 0;
	}
}

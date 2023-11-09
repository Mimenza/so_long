/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:06 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 19:56:16 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_printmap(t_game game)
{
	int i;
	int	j;
	char **map;

	map = game.map->grid;
	i = 0;
	while (map[i][j] != '\0')
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{	
	//check input file name
	t_game		game;
	char 		**grid;

	system("clear");
	ft_printf("CHECKING FILE NAME....");
	if (argc == 2 && ft_check_ext(*(argv + 1), ".ber"))
	{
		ft_printf("\033[0;32m [OK] \033[0m \n\n");

		//create game
		ft_create_game(*(argv + 1), &game);
		ft_printmap(game);
	}
	else
		ft_printf("\033[1;31m [KO] \033[0m \n-->WRONG FILE NAME  \n");
}

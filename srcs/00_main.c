/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:06 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/11 08:19:42 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

//This function checks if the str given ends in the ext.
static int	ft_check_ext(char *str, char *ext)
{
	int	size_s;
	int	size_ext;

	size_s = ft_strlen(str);
	size_ext = ft_strlen(ext);
	while (size_ext != 0 && size_s != 0)
	{
		if (str[size_s] != ext[size_ext])
			return (0);
		size_ext--;
		size_s--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game		game;

	system("clear");
	print_game_name();
	ft_printf("CHECKING FILE NAME....");
	if (argc == 2 && ft_check_ext(*(argv + 1), ".ber"))
	{
		ft_printf("\033[0;32m [OK] \033[0m \n\n");
		ft_create_game(*(argv + 1), &game);
	}
	else
		ft_print_error(0);
}

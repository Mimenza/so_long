/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:11:21 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/30 16:19:20 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 19:58:48 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_game	ft_create_game(char *strmap, t_game *game)
{	
	game->map = ft_create_map(strmap);
	game->player = ft_locate_player(game->map);
	game->exit = ft_locate_exit(game->map);
	game->coll = 0;
	game->steps	= 0;
	//game->window
	return (*game);
}
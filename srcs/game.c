/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:29:45 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 17:09:02 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

t_game	ft_create_game(char *strmap, t_game *game)
{	
	game = (t_game *)malloc(sizeof(t_game));
	game->map = ft_create_map(strmap);
	return (*game);
}
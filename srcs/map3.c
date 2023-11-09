/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:10:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 21:27:49 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int ft_print_grid(char **grid)
{
    printf("%s\n", grid[0]);
    printf("%s\n", grid[1]);
    printf("%s\n", grid[2]);
    printf("%s\n", grid[3]);
    printf("%s\n", grid[4]);
    printf("\n\n\n\n");
}

int ft_check_above(int x, int y, char **grid)
{
    if (grid[y][x - 1] && ((grid[y][x - 1] == '0') || (grid[y][x - 1] == 'C') || (grid[y][x - 1] == 'E')))
    {
        ft_printf("position above %c\n", grid[y][x - 1]);
        grid[y][x - 1] = 'P';
        ft_print_grid(grid);
        return (1);
    }
    return (0);
}

int ft_check_below(int x, int y, char **grid)
{
   
    if (grid[y][x + 1] && ((grid[y][x + 1] == '0') || (grid[y][x + 1] == 'C') || (grid[y][x + 1] == 'E')))
    {
        ft_printf("position below %c\n", grid[y][x + 1]);
        grid[y][x + 1]= 'P';
        ft_print_grid(grid);
        return (1);
    }
    return (0);
}

int ft_check_right(int x, int y, char **grid)
{
    if (grid[y + 1][x] && ((grid[y + 1][x] == '0') || (grid[y + 1][x] == 'C') || (grid[y + 1][x] == 'E')))
    {
        ft_printf("position right %c\n", grid[y + 1][x]);
        grid[y + 1][x]= 'P';
        ft_print_grid(grid);
        return (1);
    }
    return (0);
}

int ft_check_left(int x, int y, char **grid)
{
    if (grid[y - 1][x] && ((grid[y - 1][x] == '0') || (grid[y - 1][x] == 'C') || (grid[y - 1][x] == 'E')))
    {
        ft_printf("position left %c\n", grid[y - 1][x]);
        grid[y - 1][x] = 'P';
        ft_print_grid(grid);
        return (1);
    }
    return (0);
}

//looks for a player with an new moveable area
int ft_expandable(char **grid, t_player *player)
{
    int		x;
	int		y;
    int     a;
    int     b;
    int     r;
    int     l;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'P')
			{
                //WE HAVE FOUND A PLAYER
                
                a = ft_check_above(x, y, grid);
                b = ft_check_below(x, y, grid);
                r = ft_check_right(x, y, grid);
                l = ft_check_left(x, y, grid);

                if ( a == 1 || b == 1|| r == 1|| l == 1)
                    return (1);
            }
			x++;
		}
		y++;
	}

    return (0);
}

int ft_reachable(char ** grid)
{
    int		    x;
	int		    y;
    t_player    player;
    int         expandable;

    expandable = 1;
    while (expandable == 1)
    {
       expandable = ft_expandable(grid, &player);
    }
    return (0);
}
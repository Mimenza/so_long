/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:49:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/09 15:43:14 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/Libft/libft.h"

// ----------------------------------
// MACROS

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// Key Codes for MacOS
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124

// MacOS Events
# define ON_KEYDOWN		2
# define ON_KEYUP 		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17
// ----------------------------------
typedef struct s_size
{
	int		w;
	int		h;
}			t_size;

// store all information about the window
typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_size	*size;
}			t_window;

// store all information about the map
typedef struct s_map
{
	char	**grid;
	t_size	*size;
	int		n_coll;
}			t_map;

//store all the information about the exit
typedef struct s_exit
{
	int		x_pos;
	int		y_pos;
}				t_exit;

//store all the information about the player
typedef struct s_player
{
	int		x_pos;
	int		y_pos;
	int		framerate;
}				t_player;

// store all information about the game
typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	player;
	int			steps;
	int			coll;
	t_exit		exit;
}			t_game;

int		ft_check_ext(char *str, char *ext);
char	**ft_create_grid(char * strmap);
t_game	ft_create_game(char *strmap, t_game *game);
t_map	*ft_create_map(char *strmap);
t_size	*ft_map_size(char **grid);
int		ft_map_coll(char **grid);
int		ft_check_item(char c, int *player, int *exit, int *coll, int mode);
int 	ft_map_wall(char **grid, int w, int h);
int		ft_strcustom(char *str, char c);
#endif
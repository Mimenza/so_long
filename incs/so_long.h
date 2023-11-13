/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:49:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/11/13 12:35:23 by emimenza         ###   ########.fr       */
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


// Pixel size of each .xpm file (48 x 48)
# define PX	48

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

// Assets location
# define ANIMATION_FRAMES 10
# define IMG_COUNT	18
# define FLOOR		"./textures/floor/grass.xpm"
# define WALL		"./textures/wall/wall.xpm"
# define COLL		"./textures/collectable/coin_3.xpm"
# define PLAYER_U	"./textures/player/player_up.xpm"
# define PLAYER_D	"./textures/player/player_down.xpm"
# define PLAYER_L	"./textures/player/player_left.xpm"
# define PLAYER_R	"./textures/player/player_right.xpm"
# define EXIT_C		"./textures/exit/exit_c.xpm"
# define EXIT_O		"./textures/exit/exit_o.xpm"
# define COLL_A_1	"./textures/collectable/coin_1.xpm"
# define COLL_A_2	"./textures/collectable/coin_2.xpm"
# define COLL_A_3	"./textures/collectable/coin_3.xpm"
# define COLL_A_4	"./textures/collectable/coin_4.xpm"
# define COLL_A_5	"./textures/collectable/coin_5.xpm"
# define COLL_A_6	"./textures/collectable/coin_6.xpm"
# define COLL_A_7	"./textures/collectable/coin_7.xpm"
# define COLL_A_8	"./textures/collectable/coin_8.xpm"
# define ENEMY		"./textures/enemy/enemy.xpm"
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
	t_window	window;
	t_map		map;
	t_player	player;
	int			steps;
	int			coll;
	t_exit		exit;
	void		*img[IMG_COUNT];
}			t_game;

//utils.c
int		ft_check_ext(char *str, char *ext);

//game.c
t_game	ft_create_game(char *strmap, t_game *game);

//map.c
t_map	ft_create_map(char *strmap);
void	ft_start_game(t_game game);

//map1.c
char	**ft_create_grid(char * strmap);
t_size	*ft_map_size(char **grid);
int		ft_map_coll(char **grid);
int		ft_check_item(char c, int *player, int *exit, int *coll, int mode);

//map2.c
int 	ft_map_wall(char **grid, int w, int h);
int		ft_strcustom(char *str, char c);
t_player	ft_locate_player(t_map map);
t_exit		ft_locate_exit(t_map map);

//map3.c
int		ft_reachable(char **grid, t_size *size);

//map4.c
int		ft_check_items_reach(char **grid, char **p_grid);
void	ft_print_grid(char **grid);

//utils.c
char	**ft_create_doubleptr(t_size size);
void	ft_copy_doubleptr(char **grid, char **p_grid, t_size size);
void	ft_free_doubleptr(char **grid);
void	imprimirPatron();

//window.c
t_window	ft_new_window(void *mlx, int widht, int height, char *name);
int ft_close ();

//hooks.c
int	ft_input(int key, void *param);
int	ft_update (void *param);

//print_map.c
void	ft_print_map(t_game *game);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:49:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/01 22:53:29 by emimenza         ###   ########.fr       */
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
# include <math.h>
// ----------------------------------
// MACROS

// Pixel size of each .xpm file (16x16)
# define PX	16

# define SPEED 1000 // the lower the fastest the enemy moves

// Key Codes for MacOS
// # define KEY_ESC	53
// # define KEY_W		13
// # define KEY_A		0
// # define KEY_S		1
// # define KEY_D		2
// # define KEY_UP		126
// # define KEY_DOWN	125
// # define KEY_LEFT	123
// # define KEY_RIGHT	124

// MacOS Events
# define ON_KEYDOWN		2
# define ON_KEYUP 		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

// Key Codes for Linux
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		1234
# define KEY_DOWN	1234
# define KEY_LEFT	1234
# define KEY_RIGHT	1234

// Assets location
# define ANIMATION_FRAMES 1000
# define COIN_ROTATION	2000
# define IMG_COUNT	20

# define FLOOR			"./textures_custom/floor/grass.xpm"
# define WALL			"./textures_custom/wall/rock.xpm"

# define PLAYER_U		"./textures_custom/player/back.xpm"
# define PLAYER_D		"./textures_custom/player/front.xpm"
# define PLAYER_L		"./textures_custom/player/left.xpm"
# define PLAYER_R		"./textures_custom/player/right.xpm"

# define ENEMY_U		"./textures_custom/enemy/back.xpm"
# define ENEMY_D		"./textures_custom/enemy/down.xpm"
# define ENEMY_L		"./textures_custom/enemy/left.xpm"
# define ENEMY_R		"./textures_custom/enemy/right.xpm"

# define EXIT_C			"./textures_custom/exit/c_chest.xpm"
# define EXIT_O			"./textures_custom/exit/o_chest.xpm"

# define COIN_1			"./textures_custom/collectable/coin_1.xpm"
# define COIN_2			"./textures_custom/collectable/coin_2.xpm"
# define COIN_3			"./textures_custom/collectable/coin_3.xpm"
# define COIN_4			"./textures_custom/collectable/coin_4.xpm"
# define COIN_5			"./textures_custom/collectable/coin_5.xpm"
# define COIN_6			"./textures_custom/collectable/coin_6.xpm"
# define COIN_7			"./textures_custom/collectable/coin_7.xpm"
# define COIN_8			"./textures_custom/collectable/coin_8.xpm"

// ----------------------------------

typedef struct s_coords
{
	int		a;
	int		b;
	int		r;
	int		l;
}			t_coords;

typedef struct s_size
{
	int		w;
	int		h;
}			t_size;

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

// store all information about the window
typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_size	*size;
	void	*img[IMG_COUNT];
}			t_window;

// store all information about the map
typedef struct s_map
{
	char	**grid;
	t_size	*size;
	int		n_coll;
	int		created;
	int		boss;
}			t_map;

//store all the information about the exit
typedef struct s_exit
{
	t_position	position;
	int			skin;
}				t_exit;

typedef struct s_enemy
{
	t_position	position;
	int			skin;
}				t_enemy;

//store all the information about the player
typedef struct s_player
{
	t_position	pos;
	int			framerate;
	int			skin;
}				t_player;

// store all information about the game
typedef struct s_game
{
	t_window	window;
	t_map		map;
	t_player	p;
	int			steps;
	int			coll;
	int			coll_skin;
	t_exit		exit;
	int			created;
	t_enemy		*enemy;
	int			enemy_nbr;
}			t_game;

//main.c

int			ft_check_ext(char *str, char *ext);

//game.c
void		ft_load(t_game *game, char *path, int i);
void		ft_load_imgs(t_game *game);
void		ft_start_game(t_game game);
t_game		ft_create_game(char *strmap, t_game *game);

//map.c
t_map		ft_create_map(char *strmap);

//map1.c
char		*ft_read_file(char *strmap);
int			ft_create_grid(char *strmap, char ***grid);
int			ft_map_size(char **grid, t_size **size);
int			ft_map_coll(char **grid);


//map2.c
int			ft_strcustom(char *str, char c);
int			ft_map_wall(char **grid, int w, int h);
t_player	ft_locate_player(t_map map);
t_exit		ft_locate_exit(t_map map);

//map3.c
int			ft_expandable(char **grid, t_player *player);
int			ft_reachable(char **grid, t_size *size);
int			ft_count_item(char c, int *player, int *exit, int *coll);
int			ft_check_item(char c, int *player, int *exit, int *coll);

//map4.c
int			ft_check_above(int x, int y, char **grid);
int			ft_check_below(int x, int y, char **grid);
int			ft_check_right(int x, int y, char **grid);
int			ft_check_left(int x, int y, char **grid);

//map5.c
int			ft_check_items_reach(char **grid, char **p_grid);
void		ft_print_grid(char **grid);

//window.c
int			ft_close(void);
t_window	ft_new_window(void *mlx, int widht, int height, char *name);

//hooks.c
void		ft_animate_coin(t_game *game);
void		ft_input2(int key, t_game *game);
int			ft_input(int key, void *param);
int			ft_update(void *param);

//print_map.c
void		ft_put_img(t_game *game, int x, int y, int enemy_nbr);
void		ft_print_map(t_game *game);
void		ft_print_info(t_game game);

//move.c
void		ft_move_player2(t_game *game, int x, int y);
int			ft_move_player(t_game *game, int x, int y);
int			ft_move_enemy(t_game *game, int x, int y, t_position pos);

//enemy.c
void		ft_enemy_nbr(t_game *game);
void		ft_found_enemy(t_game *game);
void		ft_select_movement(t_game game, int y, int x, int direction);
int			ft_rand(void);
void		ft_randomize(t_game *game);

//error.c
void		ft_print_error(int type);

//utils.c
char		**ft_create_doubleptr(t_size size);
void		ft_copy_doubleptr(char **grid, char **p_grid, t_size size);
void		ft_free_doubleptr(char **grid);
void		print_game_name(void);
void		print_game_over(void);
void		ft_free(t_game game);

#endif
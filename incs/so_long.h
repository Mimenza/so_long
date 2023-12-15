/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emimenza <emimenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:49:15 by emimenza          #+#    #+#             */
/*   Updated: 2023/12/15 08:08:23 by emimenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/Libft/libft.h"
// ----------------------------------
// MACROS

// Pixel size of each .xpm file (16x16)
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

// Assets location
# define IMG_COUNT	6

# define FLOOR			"./textures/floor/grass.xpm"
# define WALL			"./textures/wall/rock.xpm"
# define PLAYER_D		"./textures/player/front.xpm"
# define ENEMY_D		"./textures/enemy/down.xpm"
# define EXIT_C			"./textures/exit/c_chest.xpm"
# define COIN_1			"./textures/collectable/coin_1.xpm"

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
	int		state;
}			t_map;

//store all the information about the exit
typedef struct s_exit
{
	t_position	position;
}				t_exit;

typedef struct s_enemy
{
	t_position	position;
}				t_enemy;

//store all the information about the player
typedef struct s_player
{
	t_position	pos;
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
}			t_game;

//main.c
static int		ft_check_ext(char *str, char *ext);

//game.c
static void		ft_load(t_game *game, char *path, int i);
static void		ft_cpy_imgs(char files[IMG_COUNT][42], t_game *game);
static void		ft_load_imgs(t_game *game);
static void		ft_start_game(t_game game);
t_game			ft_create_game(char *strmap, t_game *game);

//map.c
t_map			ft_create_map(char *strmap);
static char		**ft_create_and_validate_grid(char *strmap, \
t_size **size, int *n_coll);

//map1.c
static char		*ft_read_file(char *strmap, char *t_line);
int				ft_create_grid(char *strmap, char ***grid);
int				ft_map_size(char **grid, t_size **size);
int				ft_map_coll(char **grid);

//map2.c
static int		ft_strcustom(char *str, char c);
int				ft_map_wall(char **grid, int w, int h);
t_player		ft_locate_player(t_map map);
t_exit			ft_locate_exit(t_map map);

//map3.c
static int		ft_expandable(char **grid, t_player *player);
int				ft_reachable(char **grid, t_size *size);
int				ft_count_item(char c, int *player, int *exit, int *coll);
int				ft_check_item(char c, int *player, int *exit, int *coll);
int				ft_check_position(int x, int y, char **grid);

//map5.c
int				ft_check_items_reach(char **grid, char **p_grid);
void			ft_print_grid(char **grid);

//window.c
int				ft_close(void);
t_window		ft_new_window(void *mlx, int widht, int height, char *name);

//print_map.c
static void		ft_put_img(t_game *game, int x, int y, int enemy_nbr);
void			ft_print_map(t_game *game);

//hooks.c
static void		ft_input2(int key, t_game *game);
int				ft_input(int key, void *param);

//move.c
static void		ft_check_coin(t_game *game);
static void		ft_move_player2(t_game *game, int x, int y);
int				ft_move_player(t_game *game, int x, int y);

//error.c
void			ft_print_error(int type);

//utils.c
char			**ft_create_doubleptr(t_size size);
void			ft_copy_doubleptr(char **grid, char **p_grid, t_size size);
void			print_game_name(void);
void			print_game_over(void);

//free.c
void			ft_free_map_size(t_game game);
void			ft_free_win_size(t_game game);
void			ft_free_doubleptr(char **grid);
#endif
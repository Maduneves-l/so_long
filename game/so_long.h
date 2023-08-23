/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:39:13 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:12:37 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
//# include "../minilibx_linux/mlx.h"
# include "../minilibx_opengl/mlx.h"
# include <fcntl.h>

enum
{
	KEY_W = 13,
	KEY_D = 2,
	KEY_A = 0,
	KEY_S = 1,
	A_UP = 126,
	A_DOWN = 125,
	A_LEFT = 123,
	A_RIGHT = 124,
	ON_DESTROY = 17,
	K_ESC = 53
};

// enum
// {
// 	KEY_W = 119,
// 	KEY_D = 100,
// 	KEY_A = 97,
// 	KEY_S = 115,
// 	A_UP = 65362,
// 	A_DOWN = 65364,
// 	A_LEFT = 65361,
// 	A_RIGHT = 65363,
// 	K_ESC = 65307
// };

typedef struct s_map
{
	int				collect;
	int				c_temp;
	int				player_count;
	int				exit;
	int				px;
	int				py;
	int				f_exit;

}					t_map;

typedef struct s_image
{
	void			*bg;
	void			*p_front;
	void			*p_left;
	void			*p_right;
	void			*p_back;
	void			*p_curr;
	void			*collect;
	void			*wall;
	void			*exit;
	void			*ene;
}					t_image;

// typedef	struct s_enemy
// {
// 	int 	count;
// 	int 	x;
// 	int 	y;
// }t_enemy;

typedef struct s_enemy
{
	int				ex;
	int				ey;
	struct s_enemy	*next;
}					t_enemy;

typedef struct s_window
{
	void			*mlx;
	void			*mlx_win;
	char			**map;
	t_image			im;
	t_map			mapcomp;
	int				altura;
	int				largura;
	int				count_e;
	t_enemy			*enemy_list;
	unsigned int	steps;

}					t_window;

//checkmap.c
void				check_map(char **av, t_window *window);
char				**get_map(char **map, int fd, int count);
void				map_is_retangle(t_window *window);
void				check_map_character(t_window *window);
void				map_has_wall(t_window *window);

//utils_map.c
int					ft_strlen_nl(char *str);
int					map_invalid_char(char c);
int					map_all_components(t_window *window);
void				player_pos(t_window *window, int l, int c);
void				message_error(int i);

//flood_fill.c
void				init_flood_fill(t_window *window);
void				flood_fill(t_window *window, char **map_temp, int px,
						int py);

//images.c
void				init_images(t_window *window);
int					put_image(t_window *window);
void				aux_images(t_window *window, int count, int i, int j);
void				change_p_image(t_window *window, int x, int y);

//moves.c
int					key_hook(int keycode, t_window *window);
int					check_colision(t_window *window, int x, int y, char c);
void				moves(t_window *window, int x, int y);
int					key_close(int keycode, t_window *window);
void				put_enemy(t_window *window);

//clean.c
void				exit_game(char *s, t_window *window);
void				free_matrix(char **matrix);

//enemy.c
// void    count_enemy(t_window *window);
// void    choose_move(t_window *window);
// void    move_enemy(t_window *window, int i);
// void	enemy(t_window *window);
// void	moves_enemy(t_window *window, int x, int y);
t_enemy				*e_lstnew(int x, int y);
void				find_enemy(t_window *window);
void				move_e(t_window *win, t_enemy *curr, int x, int y);
void				choose_move(t_enemy *curr, t_window *win);
#endif
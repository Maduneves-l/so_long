/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:39:13 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/14 17:04:59 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	int		collect;
	int		player_count;
	int		exit;
	int 	px;
	int 	py;
	int 	f_exit;

}			t_map;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_map	mapcomp;
	int		altura;
	int		largura;

}			t_window;

//checkmap.c
void		check_map(char **av, t_window *window);
char		**get_map(char **map, int fd, int count);
void		map_is_retangle(t_window *window);
void		check_map_character(t_window *window);
void		map_has_wall(t_window *window);

//utils_map.c
int			ft_strlen_nl(char *str);
int			map_invalid_char(char c);
int			map_all_components(t_window *window);
void		player_pos(t_window *window, int l, int c);
void		message_error(int i);

//flood_fill.c
void	init_flood_fill(t_window *window);
void	flood_fill(t_window *window, char **map_temp, int px, int py);
void    free_matrix(char **matrix);

#endif
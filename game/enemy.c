/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:54:14 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/23 12:16:22 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*e_lstnew(int x, int y)
{
	t_enemy	*node;

	node = (t_enemy *)malloc(sizeof(t_enemy));
	if (!node)
		return (NULL);
	node->ex = x;
	node->ey = y;
	node->next = NULL;
	return (node);
}

void	find_enemy(t_window *window)
{
	int		i;
	int		j;
	t_enemy	*new_enemy;

	window->enemy_list = NULL;
	window->count_e = 0;
	i = -1;
	while (window->map[++i])
	{
		j = -1;
		while (window->map[i][++j])
		{
			if (window->map[i][j] == 'M')
			{
				new_enemy = e_lstnew(j, i);
				if (new_enemy)
				{
					new_enemy->next = window->enemy_list;
					window->enemy_list = new_enemy;
					window->count_e++;
				}
			}
		}
	}
}

void	move_e(t_window *win, t_enemy *curr, int x, int y)
{
	int	ex;
	int	ey;

	ex = curr->ex;
	ey = curr->ey;
	if (check_colision(win, ex + x, ey + y, 'P'))
		exit_game("👻 💀 GAME OVER 👻 💀", win);
	if (!check_colision(win, ex + x, ey + y, '1') && !check_colision(win, ex
			+ x, ey + y, 'C') && !check_colision(win, ex + x, ey + y, 'E')
		&& !check_colision(win, ex + x, ey + y, 'M'))
	{
		win->map[ey][ex] = '0';
		win->map[ey + y][ex + x] = 'M';
		curr->ex += x;
		curr->ey += y;
	}
}

void	choose_move(t_enemy *curr, t_window *win)
{
	int	i;

	i = rand() % 4;
	if (i == 0)
		move_e(win, curr, 1, 0);
	if (i == 1)
		move_e(win, curr, 0, 1);
	if (i == 2)
		move_e(win, curr, -1, 0);
	if (i == 3)
		move_e(win, curr, 0, -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:19 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/23 12:45:23 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//função para fazer o movimento do personagens com as teclas

int	key_hook(int keycode, t_window *window)
{
	if (keycode == K_ESC)
		exit_game("GIVING UP ALREADY?", window);
	else if (keycode == KEY_A || keycode == A_LEFT)
		moves(window, -1, 0);
	else if (keycode == KEY_D || keycode == A_RIGHT)
		moves(window, 1, 0);
	else if (keycode == KEY_S || keycode == A_DOWN)
		moves(window, 0, 1);
	else if (keycode == KEY_W || keycode == A_UP)
		moves(window, 0, -1);
	return (0);
}

int	check_colision(t_window *window, int x, int y, char c)
{
	if (window->map[y][x] == c)
		return (1);
	return (0);
}

void	moves(t_window *window, int x, int y)
{
	int	py;
	int	px;

	px = window->mapcomp.px;
	py = window->mapcomp.py;
	change_p_image(window, x, y);
	if (check_colision(window, px + x, py + y, 'M'))
		exit_game("👻 💀 GAME OVER 👻 💀", window);
	if (check_colision(window, px + x, py + y, 'E')
		&& window->mapcomp.collect == 0)
		exit_game("🥳!! YOU WIN !!🥳", window);
	if (!check_colision(window, px + x, py + y, '1') && !check_colision(window,
			px + x, py + y, 'E'))
	{
		if (check_colision(window, px + x, py + y, 'C'))
			window->mapcomp.collect--;
		window->map[py][px] = '0';
		window->map[py + y][px + x] = 'P';
		window->steps++;
		window->mapcomp.px += x;
		window->mapcomp.py += y;
	}
}

int	key_close(int keycode, t_window *window)
{
	(void)keycode;
	exit_game("GIVING UP ALREADY?", window);
	return (0);
}

void	put_enemy(t_window *window)
{
	t_enemy	*curr;

	curr = window->enemy_list;
	while (curr != NULL)
	{
		choose_move(curr, window);
		curr = curr->next;
	}
}

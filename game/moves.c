/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:19 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/18 16:28:59 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//função para fazer o movimento do personagens com as teclas

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 53)
		exit_game("GIVING UP ALREADY?");
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
	if (check_colision(window, px + x, py + y, 'E')
		&& window->mapcomp.collect == 0)
		exit_game("🥳!! YOU WIN !!🥳");
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
    put_image(window);
}

void	exit_game(char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_SUCCESS);
}
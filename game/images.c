/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:10:34 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/16 21:33:25 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// função para iniciar as imagens utilizadas no jogo
void	init_images(t_window *window)
{
	int	i;

	window->im.bg = mlx_xpm_file_to_image(window->mlx, "./img/backg.xpm", &i,
			&i);
	window->im.p_back = mlx_xpm_file_to_image(window->mlx, "./img/m_back.xpm",
			&i, &i);
	window->im.p_curr = mlx_xpm_file_to_image(window->mlx, "./img/m_front.xpm",
			&i, &i);
	window->im.p_left = mlx_xpm_file_to_image(window->mlx, "./img/m_left.xpm",
			&i, &i);
	window->im.p_right = mlx_xpm_file_to_image(window->mlx, "./img/m_right.xpm",
			&i, &i);
	window->im.exit = mlx_xpm_file_to_image(window->mlx, "./img/exit.xpm", &i,
			&i);
	window->im.wall = mlx_xpm_file_to_image(window->mlx, "./img/wall.xpm", &i,
			&i);
	window->im.collect = mlx_xpm_file_to_image(window->mlx, "./img/star.xpm",
			&i, &i);
}

//função para colocar as imagens na window (criada no main)
//cada caracter do mapa corresponde a uma imagem (* 32) por conta dos pixiels
void	put_image(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->altura)
	{
		j = 0;
		while (j < window->largura)
		{
			if (window->map[i][j] == '1')
				aux_images(window, 1, i, j);
			else if (window->map[i][j] == '0')
				aux_images(window, 2, i, j);
			else if (window->map[i][j] == 'C')
				aux_images(window, 3, i, j);
			else if (window->map[i][j] == 'E')
				aux_images(window, 4, i, j);
			else if (window->map[i][j] == 'P')
				aux_images(window, 5, i, j);
			j++;
		}
		i++;
	}
}

void	aux_images(t_window *window, int count, int i, int j)
{
	if (count == 1)
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->im.wall, j
			* 32, i * 32);
	if (count == 2)
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->im.bg, j
			* 32, i * 32);
	if (count == 3)
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->im.collect, j * 32, i * 32);
	if (count == 4)
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->im.exit, j
			* 32, i * 32);
	if (count == 5)
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->im.p_curr,
			j * 32, i * 32);
}
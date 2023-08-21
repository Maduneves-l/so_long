/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:16:56 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/21 16:19:29 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(char *s, t_window *window)
{
	ft_putendl_fd(s, 2);
	mlx_destroy_image(window->mlx, window->im.bg);
	mlx_destroy_image(window->mlx, window->im.collect);
	mlx_destroy_image(window->mlx, window->im.exit);
	mlx_destroy_image(window->mlx, window->im.p_back);
	mlx_destroy_image(window->mlx, window->im.p_front);
	mlx_destroy_image(window->mlx, window->im.p_left);
	mlx_destroy_image(window->mlx, window->im.p_right);
	mlx_destroy_image(window->mlx, window->im.wall);
	free_matrix(window->map);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_loop_end(window->mlx);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

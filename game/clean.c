/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:16:56 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/23 12:52:14 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_lst3delone(t_enemy *lst)
// {
// 	if (lst == NULL)
// 		return ;
// 	free(lst);
// }

// void	lst_clean(t_enemy **lst)
// {
// 	t_enemy	*current;

// 	while (*lst)
// 	{
// 		current = (*lst)->next;
// 		ft_lst3delone(current);
// 		*lst = current;
// 	}
// 	free(*lst);
// 	*lst = NULL;
// }


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
	mlx_destroy_image(window->mlx, window->im.ene);
	free_matrix(window->map);
	// lst_clean(&(window->enemy_list));
	// free(window->enemy_list);
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

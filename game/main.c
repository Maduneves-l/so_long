/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:38 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/28 16:33:51 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_window	window;

	window.steps = 0;
	if (ac != 2)
	{
		ft_putendl_fd("Wrong numbers of arguments", 2);
		exit(EXIT_FAILURE);
	}
	check_extesion(av[1]);
	check_map(av, &window);
	find_enemy(&window);
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, window.largura * 32,
			window.altura * 32, "Mario_game!!");
	init_images(&window);
	put_image(&window);
	mlx_hook(window.mlx_win, 2, 1L << 0, key_hook, &window);
	mlx_loop_hook(window.mlx, put_image, &window);
	mlx_hook(window.mlx_win, 17, 0, key_close, &window);
	mlx_loop(window.mlx);
}


 void	check_extesion(char *av)
 {
	if (ft_strncmp(ft_strchr(av, '.'), ".ber\0", 5) != 0)
	{
		ft_putendl_fd(" Map: Wrong extension", 2);
		exit(EXIT_FAILURE);
	}
 }

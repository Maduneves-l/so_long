/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:38 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:10:13 by mneves-l         ###   ########.fr       */
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
	check_map(av, &window);
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, window.largura * 32,
			window.altura * 32, "Mario_game!!");
	init_images(&window);
	put_image(&window);
	mlx_hook(window.mlx_win, 2, 1L << 0, key_hook, &window);
	mlx_loop_hook(window.mlx, put_image, &window);
	mlx_hook(window.mlx_win, 17, 0, key_close, &window);
	
	printf("%c", window.map[8][6]);
	printf("%c", window.map[6][10]);
	printf("%c", window.map[6][1]);
	printf("%c", window.map[3][3]);

	mlx_loop(window.mlx);
	
}

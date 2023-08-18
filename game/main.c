/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:38 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/18 16:22:13 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_window	window;

	window.steps = 0;
	//window = (t_window *)malloc(sizeof(t_window));
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
	mlx_key_hook(window.mlx_win, key_hook, &window);
	mlx_loop(window.mlx);
}

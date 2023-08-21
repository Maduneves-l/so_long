/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:54:33 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/21 16:24:03 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//função para fazer uma cópia do mapa para usar no flood fill
// e depois verificar se o path do mapa é válido

void	init_flood_fill(t_window *window)
{
	char	**map_temp;
	int		i;

	i = -1;
	window->mapcomp.f_exit = 0;
	window->mapcomp.c_temp = window->mapcomp.collect;
	map_temp = (char **)malloc(sizeof(char *) * (window->altura + 1));
	if (!map_temp)
		return ;
	while (window->map[++i])
		map_temp[i] = ft_strdup(window->map[i]);
	map_temp[i] = NULL;
	flood_fill(window, map_temp, window->mapcomp.px, window->mapcomp.py);
	free_matrix(map_temp);
	if (window->mapcomp.c_temp != 0 || window->mapcomp.f_exit != 1)
		message_error(6);
}

//função para verificar se o caminho que o jogador percorre é válido
//verifica se os 'C' foram todos coletados e se a saída é acessível
// G = caminhos que o player já passou

void	flood_fill(t_window *window, char **map_temp, int px, int py)
{
	if (map_temp[py][px] == 'G' || map_temp[py][px] == '1')
		return ;
	else if (map_temp[py][px] == 'C')
		window->mapcomp.c_temp--;
	else if (map_temp[py][px] == 'E')
	{
		window->mapcomp.f_exit = 1;
		return ;
	}
	map_temp[py][px] = 'G';
	flood_fill(window, map_temp, px + 1, py);
	flood_fill(window, map_temp, px - 1, py);
	flood_fill(window, map_temp, px, py + 1);
	flood_fill(window, map_temp, px, py - 1);
}

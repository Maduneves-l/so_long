/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:31:50 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/29 13:25:49 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// função para calcular tamanho da linha e também
// verificar se não tem espaços entre os caracteres
int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

//função para ver se os caracteres do mapa são todos
// válidos

int	map_invalid_char(char c)
{
	if (ft_strchr("PCEM01\n", c))
		return (0);
	return (1);
}

//função para verificar se tem caracter repetido
//Verificar se tem pelo menos 1PECM e que não se repetem (exceto c)

int	map_all_components(t_window *window)
{
	int	l;
	int	c;

	l = -1;
	window->mapcomp.player_count = 0;
	window->mapcomp.collect = 0;
	window->mapcomp.exit = 0;
	while (++l < window->altura)
	{
		c = -1;
		while (++c < window->largura)
		{
			if (window->map[l][c] == 'P')
				player_pos(window, l, c);
			if (window->map[l][c] == 'C')
				window->mapcomp.collect++;
			if (window->map[l][c] == 'E')
				window->mapcomp.exit++;
		}
	}
	if (window->mapcomp.player_count != 1 || window->mapcomp.exit != 1
		|| !window->mapcomp.collect)
		return (1);
	return (0);
}

//função para guardar a posição inicial do player

void	player_pos(t_window *window, int l, int c)
{
	window->mapcomp.player_count++;
	window->mapcomp.py = l;
	window->mapcomp.px = c;
}

void	message_error(int i, t_window *window)
{
	ft_putendl_fd("Error:", 2);
	if (i == 1)
		ft_putendl_fd("Map is invalid, remove empty lines", 2);
	if (i == 2)
		ft_putendl_fd("Invalid map, wrong size", 2);
	if (i == 3)
		ft_putendl_fd("Check map: wrong character :(", 2);
	if (i == 4)
		ft_putendl_fd("Check map: wrong number of components :(", 2);
	if (i == 5)
		ft_putendl_fd("Check map: Missing wall :(", 2);
	if (i == 6)
		ft_putendl_fd("Check map: Invalid path :(", 2);
	free_matrix(window->map);
	exit(EXIT_FAILURE);
}

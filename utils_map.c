/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:31:50 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/10 15:48:50 by mneves-l         ###   ########.fr       */
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

	l = 0;
	window->mapcomp.player = 0;
	window->mapcomp.collect = 0;
	window->mapcomp.exit = 0;
	while (l < window->altura)
	{
		c = -1;
		while (++c < window->largura)
		{
			if (window->map[l][c] == 'P')
				window->mapcomp.player++;
			if (window->map[l][c] == 'C')
				window->mapcomp.collect++;
			if (window->map[l][c] == 'E')
				window->mapcomp.exit++;
		}
		l++;
	}
	if (window->mapcomp.player != 1 || window->mapcomp.exit != 1
		|| !window->mapcomp.collect)
		return (1);
	return (0);
}

void	message_error(int i)
{
	if (i == 1)
		ft_putendl_fd("Map is invalid, remove empty lines", 2);
	if (i == 2)
		ft_putendl_fd("Invalid map, wrong size", 2);
	if (i == 3)
		ft_putendl_fd("Check map: wrong character :(", 2);
	if (i == 4)
		ft_putendl_fd("Check map: wrong number of components :(", 2);
	if(i == 5)
		ft_putendl_fd("Check map: Missing wall :(", 2);
	exit(EXIT_FAILURE);
}

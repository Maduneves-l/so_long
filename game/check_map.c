/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:57 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/29 11:48:35 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// funções para checar o mapa do jogo
#include "so_long.h"

//recebe av[1] (o mapa) e *window que é pointer para a struct
//abre o arquivo e começa a verificar se o mapa é válido

void	check_map(char **av, t_window *window)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putendl_fd("Error opening the map", 2);
		exit(EXIT_FAILURE);
	}
	window->map = get_map(NULL, fd, 0);
	map_is_retangle(window);
	map_has_wall(window);
	check_map_character(window);
	init_flood_fill(window);
}

// função recursiva para ler o file que está o mapa com gnl
// e colocar esse map dentro de uma matrix para ser mais fácil o acesso
// o mapa será acessado por linhas e colunas

char	**get_map(char **map, int fd, int count)
{
	char	*s;

	s = get_next_line(fd);
	if (s)
		map = get_map(map, fd, count + 1);
	if (!map && count != 0)
		map = malloc((sizeof(char *)) * (count + 1));
	if (!map)
		exit(EXIT_FAILURE);
	map[count] = s;
	return (map);
}

//verifica se o mapa é retângulo, ou seja, as linhas tem o mesmo tamanho
//verifica se não tem espaços vazios no início do mapa

void	map_is_retangle(t_window *window)
{
	int	i;

	i = 0;
	if (!ft_strlen_nl(window->map[0]))
		message_error(1, window);
	window->largura = ft_strlen_nl(window->map[0]);
	while (window->map[i])
	{
		if (ft_strlen_nl(window->map[0]) != ft_strlen_nl(window->map[i]))
			message_error(2, window);
		i++;
	}
	window->altura = i;
}

//função que percorre a matrix e verifica se os caracteres são válidos
//além disso, verifica se tem caracter duplicado ou faltando
void	check_map_character(t_window *window)
{
	int	l;
	int	c;

	l = 0;
	while (l < window->altura)
	{
		c = 0;
		while (c < window->largura)
		{
			if (map_invalid_char(window->map[l][c]))
				message_error(3, window);
			c++;
		}
		l++;
	}
	if (map_all_components(window))
		message_error(4, window);
}

//função para verficar se o mapa está fechado com parede (1)
void	map_has_wall(t_window *window)
{
	int	line;
	int	col;

	col = 0;
	line = 1;
	while (line < window->altura)
	{
		while (col < window->largura)
		{
			if (window->map[0][col] != '1')
				message_error(5, window);
			col++;
		}
		if (window->map[line][0] != '1' || window->map[line][col - 1] != '1')
			message_error(5, window);
		line++;
	}
	col = 0;
	while (col < window->largura)
	{
		if (window->map[line - 1][col] != '1' || window->altura == 1)
			message_error(5, window);
		col++;
	}
}

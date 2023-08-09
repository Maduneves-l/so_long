/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:57 by mneves-l          #+#    #+#             */
/*   Updated: 2023/08/09 14:31:31 by mneves-l         ###   ########.fr       */
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
		perror("Error opening the map");
		exit(EXIT_FAILURE);
	}
	window->map = get_map(NULL, fd, 0);
	map_is_retangle(window);
	check_map_character(window);
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
	{
		ft_putendl_fd("Map is invalid, remove empty lines", 2);
		exit(EXIT_FAILURE);
	}
	window->largura = ft_strlen_nl(window->map[0]);
	while (window->map[i] && window->map[i][0] != '\n')
	{
		if (ft_strlen_nl(window->map[0]) != ft_strlen_nl(window->map[i]))
		{
			ft_putendl_fd("Invalid map, wrong size", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	window->altura = i;
}

//função para
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
			{
				ft_putendl_fd("Check map: wrong character :(", 2);
				exit(EXIT_FAILURE);
			}
			if (map_all_components(window))
			{
				ft_putendl_fd("Check map: wrong number of components :(", 2);
				exit(EXIT_FAILURE);
			}
			c++;
		}
		l++;
	}
}

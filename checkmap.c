#include "so_long.h"

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
	check_map_complete(window);

}

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

// window->map[l][c] != '1' || window->map[l][c] != '0'
// 				|| window->map[l][c] != 'P' || window->map[l][c] != 'C'
// 				|| window->map[l][c] != 'E' || window->map[l][c] != 'M'
// 				|| !window->map[l][c] || window->map[l][c] != '\n'

void	check_map_complete(t_window *window)
{
	int l;
	int c;

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
			// if (!map_all_components(window, l, c))
			// {
			// 	ft_putendl_fd("Check map: wrong number of components :(", 2);
			// 	exit(EXIT_FAILURE);
			// }
			c++;
		}
		l++;
	}
}
#include "so_long.h"

int     ft_strlen_nl(char *str)
{
	int i;
	i = 0;

	while(str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	return i;
}

int 	map_invalid_char(char c)
{
	if(ft_strchr("PCEM01\n", c))
		return 0;
	return (1);
}

// void 	map_all_components(t_window *window, int l, int c)
// {

// }
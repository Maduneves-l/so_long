/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:24:52 by mneves-l          #+#    #+#             */
/*   Updated: 2023/03/30 17:13:18 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *size)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", size);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], size);
		i++;
	}
}

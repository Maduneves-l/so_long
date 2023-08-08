/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:41:22 by mneves-l          #+#    #+#             */
/*   Updated: 2023/03/30 16:58:37 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int nb, char *base, int *size)
{
	if (nb / 16 == 0)
	{
		ft_putchar(base[nb], size);
		return ;
	}
	ft_puthex(nb / 16, base, size);
	ft_putchar(base[nb % 16], size);
}

void	ft_check(unsigned int nb, int i, int *size)
{
	if (i == 1)
		ft_puthex(nb, HEX_UPPER, size);
	if (i == 2)
		ft_puthex(nb, HEX_LOWER, size);
}

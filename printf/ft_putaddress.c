/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:42:53 by mneves-l          #+#    #+#             */
/*   Updated: 2023/04/14 17:18:13 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(unsigned long int nbr, int *size)
{
	if (!nbr)
		ft_putstr("(nil)", size);
	else
	{
		if (nbr < 16)
		{
			ft_putstr("0x", size);
			ft_putchar(HEX_LOWER[nbr % 16], size);
			return ;
		}
		ft_putaddress((nbr / 16), size);
		ft_putchar(HEX_LOWER[nbr % 16], size);
	}
}

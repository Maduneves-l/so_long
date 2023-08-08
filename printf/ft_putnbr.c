/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:33:07 by mneves-l          #+#    #+#             */
/*   Updated: 2023/03/30 16:53:31 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *size)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", size);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', size);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr((nb / 10), size);
		ft_putnbr((nb % 10), size);
	}
	else
		ft_putchar((nb + 48), size);
}

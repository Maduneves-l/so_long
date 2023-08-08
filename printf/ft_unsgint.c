/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsgint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:37:18 by mneves-l          #+#    #+#             */
/*   Updated: 2023/03/30 16:58:53 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsgint(unsigned int nb, int *size)
{
	if (nb >= 10)
	{
		ft_unsgint((nb / 10), size);
		ft_unsgint((nb % 10), size);
	}
	else
		ft_putchar((nb + 48), size);
}

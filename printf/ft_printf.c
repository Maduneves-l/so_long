/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:45:16 by mneves-l          #+#    #+#             */
/*   Updated: 2023/04/15 13:48:49 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_placeholders(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_print_formats(va_list arg, char c, int *size)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), size);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), size);
	else if (c == 'p')
		ft_putaddress(va_arg(arg, unsigned long), size);
	else if (c == 'd')
		ft_putnbr(va_arg(arg, int), size);
	else if (c == 'i')
		ft_putnbr(va_arg(arg, int), size);
	else if (c == 'u')
		ft_unsgint(va_arg(arg, unsigned int), size);
	else if (c == 'x')
		ft_check(va_arg(arg, unsigned int), 2, size);
	else if (c == 'X')
		ft_check(va_arg(arg, unsigned int), 1, size);
	else if (c == '%')
		ft_putchar('%', size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		size;

	size = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_placeholders(str[i + 1]))
			ft_print_formats(arg, str[++i], &size);
		else
			ft_putchar(str[i], &size);
		i++;
	}
	va_end(arg);
	return (size);
}

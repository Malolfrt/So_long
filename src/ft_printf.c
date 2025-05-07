/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:22:48 by mlefort           #+#    #+#             */
/*   Updated: 2023/12/08 14:39:46 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_flags(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_flags_control(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	if (c == '%')
		len += ft_putchar('%');
	if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		len += ft_putnbr_u(va_arg(arg, unsigned int));
	if (c == 'x')
		len += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
		len += ft_checkp(va_arg(arg, unsigned long long), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_flags(str[i + 1]))
		{
			len += ft_flags_control(arg, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

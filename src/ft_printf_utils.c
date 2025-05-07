/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:23:18 by mlefort           #+#    #+#             */
/*   Updated: 2023/12/08 14:39:59 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		n = n + '0';
		count += ft_putchar(n);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putnbr_u(n % 10);
	}
	else
	{
		n = n + '0';
		count += ft_putchar(n);
	}
	return (count);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_putnbr_base(n / 16, base);
		count += ft_putnbr_base(n % 16, base);
	}
	else
	{
		count += ft_putchar(base[n]);
	}
	return (count);
}

int	ft_checkp(unsigned long long n, char *base)
{
	int	count;

	count = 0;
	if (!n)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
		count += ft_putstr("0x");
	if (n > 15)
	{
		count += ft_putnbr_base((n / 16), base);
		count += ft_putnbr_base((n % 16), base);
	}
	else
	{
		count += ft_putchar(base[n]);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:14:35 by mlefort           #+#    #+#             */
/*   Updated: 2023/12/08 14:41:20 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_flags(char c);
int	ft_flags_control(va_list arg, char c);

int	ft_putchar(char c);
int	ft_putstr(char *str);

int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr_base(unsigned long long n, char *base);
int	ft_checkp(unsigned long long n, char *base);

#endif
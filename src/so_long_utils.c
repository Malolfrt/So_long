/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:58:30 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/27 14:08:04 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	ft_putchar_error(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return ;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_error(char *str, char **tab)
{
	if (!str)
		str = " ";
	if (tab)
		free_tab(tab);
	ft_putchar_error("Error\n");
	if (str)
		ft_putchar_error(str);
	exit(1);
}

int	ft_strcmp_char(char c, char d)
{
	if (d == '\n')
		return (0);
	return (c - d);
}

int	ft_strlen_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

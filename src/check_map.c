/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:39:52 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/19 13:46:47 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(char	**map)
{
	int	len;
	int	i;

	len = 0;
	if (!map ||!map[0])
		return (0);
	while (map[len] != NULL)
		len++;
	len -= 1;
	i = 0;
	while (map[0][i])
	{
		if (ft_strcmp_char('1', map[0][i]) != 0)
			ft_error("la map n'est pas fermer", map);
		i++;
	}
	i = 0;
	while (map[len][i])
	{
		if (ft_strcmp_char('1', map[len][i]) != 0)
			ft_error("la map n'est pas fermer", map);
		i++;
	}
	return (1);
}

static int	check_rectangle(char **map)
{
	int	len;
	int	size;
	int	i;

	len = 0;
	if (!map || !map[0])
		return (0);
	while (map[len] != NULL)
		len++;
	size = ft_strlen_map(map[0]);
	i = 0;
	while (i < len)
	{
		if (ft_strlen_map(map[i]) != size)
			ft_error("la map n'est pas rectangle", map);
		i++;
	}
	return (1);
}

static int	check_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map || !map[0])
		return (0);
	while (map[i])
	{
		if (map[i][0] != '1')
			ft_error("la map n'est pas fermer", map);
		if (map[i][ft_strlen_map(map[i]) - 1] != '1')
			ft_error("la map n'est pas fermer", map);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
				ft_error("la map n'a pas les bon items", map);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_valid_items(char	**map)
{
	int	j;

	int (i) = 0;
	int (player) = 0;
	int (exit) = 0;
	int (collectible) = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		ft_error("Les items ne sont pas bons", map);
	return (1);
}

int	check_map(char **map)
{
	if (!check_valid(map))
		return (0);
	if (!check_rectangle(map))
		return (0);
	if (!check_wall(map))
		return (0);
	if (!check_valid_items(map))
		return (0);
	return (1);
}

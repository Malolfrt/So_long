/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:54:15 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/20 16:20:32 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flags(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (1);
	else if (c == 'P')
		return (1);
	return (0);
}

void	flood_file_map(char **map, int i, int j)
{
	if (flags(map[i][j]))
	{
		map[i][j] = 'A';
		flood_file_map(map, i, j + 1);
		flood_file_map(map, i, j - 1);
		flood_file_map(map, i + 1, j);
		flood_file_map(map, i - 1, j);
	}
}

void	flood_file_start(char **map)
{
	int		j;
	char	**map_cpy;

	int (i) = 0;
	map_cpy = NULL;
	map_cpy = ft_cpy_tab(map_cpy, map);
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'P')
			{
				flood_file_map(map_cpy, i, j);
				if (!map_is_valid(map_cpy))
				{
					free_tab(map_cpy);
					ft_error("le chemin n'est pas valide", map);
				}
			}
			j++;
		}
		i++;
	}
	free_tab(map_cpy);
}

int	map_is_valid(char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'E' || map_cpy[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

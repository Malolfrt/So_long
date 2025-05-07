/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:05:43 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/26 17:47:26 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_right(t_data *data)
{
	if (data->map[data->x][data->y + 1] != '1')
	{
		if (data->map[data->x][data->y] == 'E')
		{
			move_from_e(data, data->x, (data->y + 1));
			data->y++;
		}
		else
		{
			move_normal(data, data->x, (data->y + 1));
			data->y++;
		}
	}
}

void	go_left(t_data *data)
{
	if (data->map[data->x][data->y - 1] != '1')
	{
		if (data->map[data->x][data->y] == 'E')
		{
			move_from_e(data, data->x, (data->y - 1));
			data->y--;
		}
		else
		{
			move_normal(data, data->x, (data->y - 1));
			data->y--;
		}
	}
}

void	go_up(t_data *data)
{
	if (data->map[data->x - 1][data->y] != '1')
	{
		if (data->map[data->x][data->y] == 'E')
		{
			move_from_e(data, (data->x - 1), data->y);
			data->x--;
		}
		else
		{
			move_normal(data, (data->x - 1), data->y);
			data->x--;
		}
	}
}

void	go_down(t_data *data)
{
	if (data->map[data->x + 1][data->y] != '1')
	{
		if (data->map[data->x][data->y] == 'E')
		{
			move_from_e(data, (data->x + 1), data->y);
			data->x++;
		}
		else
		{
			move_normal(data, (data->x + 1), data->y);
			data->x++;
		}
	}
}

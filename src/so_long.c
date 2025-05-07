/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:06:30 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/27 14:19:15 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_data *data, int i)
{
	ft_error_img(data);
	free_tab(data->map);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	if (i == 1)
		ft_error("La map est trop grande", NULL);
	exit (0);
	return (0);
}

int	ft_close_window_map_too_big(t_data *data)
{
	ft_error_img(data);
	free_tab(data->map);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	ft_error("La map est trop grande", NULL);
	exit (0);
	return (0);
}

static int	on_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close_window(data, 0);
	else if (keycode == UP)
		go_up(data);
	else if (keycode == RIGTH)
		go_right(data);
	else if (keycode == LEFT)
		go_left(data);
	else if (keycode == DOWN)
		go_down(data);
	return (0);
}

void	so_long(char **map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (free_tab(map));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data->map));
	map_init(map, data);
	init_data_value(data);
	ft_init_window(data);
	ft_put_map_to_window(data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_close_window, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
	mlx_loop(data->mlx_ptr);
	return ;
}

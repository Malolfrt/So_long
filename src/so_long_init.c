/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:20:47 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/26 14:23:28 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_1, (100 * j), (100 * i));
}

void	ft_player(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_p, (100 * j), (100 * i));
}

void	ft_collectible(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_c, (100 * j), (100 * i));
}

void	ft_open(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_0, (100 * j), (100 * i));
}

void	ft_exit(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_e, (100 * j), (100 * i));
}

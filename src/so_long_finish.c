/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_finish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:44:27 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/27 13:31:39 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_victoire(t_data *data)
{
	ft_printf("BRAVO, tu as gagner en %d coups\n", data->compteur);
	ft_close_window(data, 0);
}

void	check_exit(t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		ft_victoire(data);
	else
		return ;
}

void	move_normal(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_p, (y * 100), (x * 100));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_0, (data->y * 100), (data->x * 100));
	data->compteur++;
	ft_printf("%d\n", data->compteur);
	data->map[data->x][data->y] = '0';
	if (data->map[x][y] == 'E')
		check_exit(data);
}

void	move_from_e(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_p, (y * 100), (x * 100));
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_e, (data->y * 100), (data->x * 100));
	data->compteur++;
	ft_printf("%d\n", data->compteur);
}

void	ft_error_img(t_data *data)
{
	if (data->img.img_0)
		mlx_destroy_image(data->mlx_ptr, data->img.img_0);
	if (data->img.img_1)
		mlx_destroy_image(data->mlx_ptr, data->img.img_1);
	if (data->img.img_c)
		mlx_destroy_image(data->mlx_ptr, data->img.img_c);
	if (data->img.img_e)
		mlx_destroy_image(data->mlx_ptr, data->img.img_e);
	if (data->img.img_p)
		mlx_destroy_image(data->mlx_ptr, data->img.img_p);
}

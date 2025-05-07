/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:30:06 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/27 14:20:55 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(char **tab, t_data *data)
{
	int		i;
	int		len;

	data->map = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	if (!data->map)
		return (free_tab(tab));
	i = 0;
	while (i < ft_tablen(tab))
	{
		len = ft_strlen(tab[i]);
		data->map[i] = malloc(sizeof(char) * (len + 1));
		if (!data->map[i])
			return (free_tab(data->map), free_tab(tab));
		data->map[i] = ft_strcpy(data->map[i], tab[i]);
		i++;
	}
	data->map[i] = NULL;
	free_tab(tab);
	return ;
}

void	ft_put_map_to_window(t_data *data)
{
	int	j;

	int (i) = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '\n')
				break ;
			if (data->map[i][j] == '1')
				ft_wall(data, i, j);
			if (data->map[i][j] == '0')
				ft_open(data, i, j);
			if (data->map[i][j] == 'P')
				ft_player(data, i, j);
			if (data->map[i][j] == 'C')
				ft_collectible(data, i, j);
			if (data->map[i][j] == 'E')
				ft_exit(data, i, j);
			j++;
		}
		i++;
	}
}

void	ft_init_window(t_data *data)
{
	data->height_win = (ft_tablen(data->map) * 100);
	data->width_win = ((ft_strlen(data->map[0]) * 100) - 100);
	if (data->height_win > 1400 || data->width_win > 2500)
		ft_close_window_map_too_big(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width_win,
			data->height_win, "SO_LONG");
	if (!data->win_ptr)
		ft_close_window(data, 0);
	return ;
}

void	find_player(t_data *data)
{
	data->x = 0;
	while (data->map[data->x])
	{
		data->y = 0;
		while (data->map[data->x][data->y])
		{
			if (data->map[data->x][data->y] == 'P')
				return ;
			data->y++;
		}
		data->x++;
	}
}

void	init_data_value(t_data *data)
{
	data->img.width = 100;
	data->img.height = 100;
	data->img.img_1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/Brick100.xpm", &data->img.width, &data->img.height);
	if (data->img.img_1 == 0)
		ft_error_img(data);
	data->img.img_0 = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/sol100.xpm", &data->img.width, &data->img.height);
	if (data->img.img_0 == 0)
		ft_error_img(data);
	data->img.img_c = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/bones100.xpm", &data->img.width, &data->img.height);
	if (data->img.img_c == 0)
		ft_error_img(data);
	data->img.img_p = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/crane100.xpm", &data->img.width, &data->img.height);
	if (data->img.img_p == 0)
		ft_error_img(data);
	data->img.img_e = mlx_xpm_file_to_image(data->mlx_ptr,
			"xpm/coeur100.xpm", &data->img.width, &data->img.height);
	if (data->img.img_e == 0)
		ft_error_img(data);
	data->compteur = 0;
	find_player(data);
}

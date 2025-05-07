/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:36:10 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/27 14:18:43 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ESC 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGTH 100
# define WITDH 1200
# define HEIGTH 800

# include <unistd.h> // write, read...
# include <stdlib.h> // malloc, free...
# include <fcntl.h>	// open, close...
# include "../mlx/mlx.h" // MLX...
# include "../X11/X.h" // DestroyNotify, StructureNotify
# include "get_next_line.h" // Get Next Line...
# include "ft_printf.h" // ft_printf...

typedef struct s_img
{
	void	*img_0;
	void	*img_1;
	void	*img_c;
	void	*img_p;
	void	*img_e;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width_win;
	int		height_win;
	int		x;
	int		y;
	int		compteur;
	t_img	img;
}	t_data;

/*		check_map.c		*/
int		check_map(char **tab);

/*		get_map.c		*/
char	**get_map_init(char *filename);
void	check_name_ber(char *str);

/*		so_long_utils.c		*/
int		ft_strcmp_char(char c, char d);
int		ft_strlen_map(char *str);
void	free_tab(char **tab);
void	ft_error(char *str, char **tab);

/*		flood_file_map.c		*/
void	flood_file_start(char **map);
void	flood_file_map(char **map, int i, int j);
int		map_is_valid(char **map_cpy);

/*		flood_file_utils.c		*/
int		ft_tablen(char **tab);
char	**ft_cpy_tab(char **dst, char **src);

/*		map_init.c		*/
void	map_init(char **tab, t_data *data);
void	ft_put_map_to_window(t_data *data);
void	ft_init_window(t_data *data);
void	find_player(t_data *data);
void	init_data_value(t_data *data);

/*		so_long.c		*/
void	so_long(char **map);
int		ft_close_window(t_data *data, int i);
int		ft_close_window_map_too_big(t_data *data);

/*		so_long_init.c		*/
void	ft_exit(t_data *data, int i, int j);
void	ft_open(t_data *data, int i, int j);
void	ft_collectible(t_data *data, int i, int j);
void	ft_player(t_data *data, int i, int j);
void	ft_wall(t_data *data, int i, int j);

/*		mouvement.c		*/
void	go_up(t_data *data);
void	go_right(t_data *data);
void	go_down(t_data *data);
void	go_left(t_data *data);

/*		so_long_finish.c		*/
void	move_normal(t_data *data, int x, int y);
void	move_from_e(t_data *data, int x, int y);
void	ft_victoire(t_data *data);
void	check_exit(t_data *data);
void	ft_error_img(t_data *data);

/*		Get_Next_line.c		*/
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif
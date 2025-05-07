/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:11:06 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/26 18:00:57 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_fd_size(char *filename)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("le fichier n'est pas lisible", NULL);
	line = get_next_line(fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (size);
}

static char	**get_map(char *filename, char **tab)
{
	char	*line;
	int		len;
	int		fd;

	int (i) = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		tab[i] = malloc(sizeof(char) * (len + 1));
		if (!tab[i])
		{
			free_tab(tab);
			free(line);
			return (NULL);
		}
		tab[i] = ft_strcpy(tab[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	tab[i] = NULL;
	close(fd);
	return (tab);
}

char	**get_map_init(char *filename)
{
	char	**map;
	int		len;

	len = get_fd_size(filename);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	map = get_map(filename, map);
	return (map);
}

void	is_folder(char *str)
{
	int		fd;
	char	*line;

	if (!str)
		ft_error("Veuillez inserer un argument", NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("le fichier n'est pas lisible", NULL);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		ft_error("C'est un dossier / le fichier est vide", NULL);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return ;
}

void	check_name_ber(char *str)
{
	int	len;
	int	i;

	is_folder(str);
	len = ft_strlen(str);
	while (len > 4)
	{
		str++;
		len--;
	}
	i = 0;
	if (ft_strcmp_char(str[i], '.') == 0)
		i++;
	if (ft_strcmp_char(str[i], 'b') == 0)
		i++;
	if (ft_strcmp_char(str[i], 'e') == 0)
		i++;
	if (ft_strcmp_char(str[i], 'r') == 0)
		i++;
	if (str[i] == '\0')
		return ;
	else
		ft_error("Mauvaise extension", NULL);
}

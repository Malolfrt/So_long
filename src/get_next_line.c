/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:45:53 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/19 09:29:29 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash_v1(int fd, char *stash, int nb_read)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nb_read] = '\0';
		if (!stash)
		{
			stash = malloc(sizeof(char) * (nb_read + 1));
			stash = ft_strcpy(stash, buf);
		}
		else
			stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

static char	*ft_put_stash_in_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	temp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			nb_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nb_read = 1;
	if (!stash)
		stash = NULL;
	stash = read_and_stash_v1(fd, stash, nb_read);
	if (!stash)
		return (NULL);
	line = ft_put_stash_in_line(stash);
	stash = ft_clean_stash(stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

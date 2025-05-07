/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:42:01 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/19 16:56:42 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_tablen(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
	{
		size++;
	}
	return (size);
}

char	**ft_cpy_tab(char **dst, char **src)
{
	int	len;
	int	i;

	i = 0;
	len = ft_tablen(src);
	dst = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		len = ft_strlen(src[i]);
		dst[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!dst[i])
		{
			free_tab(dst);
			return (NULL);
		}
		dst[i] = ft_strcpy(dst[i], src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emapvalidation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:53:22 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/09 13:56:56 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

t_sqare	**emap_alloc(char **arr, t_parse_data *data)
{
	size_t	i[3];
	t_sqare	**emap;

	i[1] = 0;
	i[0] = 0;
	while (arr[i[0]])
	{
		i[2] = ft_strlen(arr[i[0]]);
		if (i[1] < i[2])
			i[1] = i[2];
		i[0]++;
	}
	emap = ft_calloc(i[0] + 3, sizeof(t_sqare *));
	if (emap == NULL)
		return (NULL);
	data->wide = i[1] + 2;
	data->tall = i[0] + 1;
	i[0] = 0;
	while (i[0] < data->tall)
	{
		emap[i[0]] = ft_calloc(i[1] + 2, sizeof(t_sqare));
		if (++i[0] && emap[i[0] - 1] == NULL )
			return (free_arr((void ***)& emap), NULL);
	}
	return (emap);
}

t_sqare	get_tile_enum(char c)
{
	if (c == '1')
		return (WALL);
	else if (c == '0')
		return (FLOOR);
	else if (c == ' ')
		return (EMPTY);
	else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		return (PLAYER);
	return (EMPTY);
}

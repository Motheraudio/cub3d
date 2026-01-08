/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emapvalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:31:20 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:31:52 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static t_sqare	**emap_alloc(char **arr, t_parse_data *data)
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
		if (emap[i[0]] == NULL || ++i[0])
			return (free_arr((void ***)& emap), NULL);
	}
	return (emap);
}

t_sqare	**convert_to_enum(char **arr, t_parse_data *data)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	data->emap = emap_alloc(arr, data);
	if (data->emap == NULL)
		return (NULL);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '1')
				data->emap[i + 1][j + 1] = WALL;
			else if (arr[i][j] == '0')
				data->emap[i + 1][j + 1] = FLOOR;
			else if (arr[i][j] == ' ')
				data->emap[i + 1][j + 1] = EMPTY;
			else if (arr[i][j] == 'W')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = WEST;
			}
			else if (arr[i][j] == 'E')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = EAST;
			}
			else if (arr[i][j] == 'N')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = NORTH;
			}
			else if (arr[i][j] == 'S')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = SOUTH;
			}
			else if (arr[i][j] != '\n')
				return (NULL);
			j ++;
		}
		i ++;
	}
	return (data->emap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emapvalidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:31:20 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/09 13:54:03 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static t_compas	get_player_orientation(char c)
{
	if (c == 'W')
		return (WEST);
	else if (c == 'E')
		return (EAST);
	else if (c == 'N')
		return (NORTH);
	else if (c == 'S')
		return (SOUTH);
	return (UNI);
}

static int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == ' '
		|| c == 'W' || c == 'E' || c == 'N'
		|| c == 'S' || c == '\n');
}

static int	handle_player_tile(char c, t_parse_data *data)
{
	t_compas	new_orientation;

	if (c != 'W' && c != 'E' && c != 'N' && c != 'S')
		return (1);
	if (data->orientation != UNI)
		return (0);
	new_orientation = get_player_orientation(c);
	data->orientation = new_orientation;
	return (1);
}

static int	process_tile(char c, size_t i, size_t j, t_parse_data *data)
{
	if (!is_valid_map_char(c))
		return (0);
	data->emap[i + 1][j + 1] = get_tile_enum(c);
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
	{
		if (! handle_player_tile(c, data))
			return (0);
	}
	return (1);
}

t_sqare	**convert_to_enum(char **arr, t_parse_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	data->emap = emap_alloc(arr, data);
	if (data->emap == NULL)
		return (NULL);
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!process_tile(arr[i][j], i, j, data))
				return (NULL);
			j++;
		}
		i++;
	}
	if (data->orientation == UNI)
		return (NULL);
	return (data->emap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:38:49 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:41:15 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static int	all_set(t_parse_data *data)
{
	if (data->celing_set == 0)
		return (-1);
	if (data->floor_set == 0)
		return (-1);
	if (data->w_texture == NULL)
		return (-1);
	if (data->e_texture == NULL)
		return (-1);
	if (data->n_texture == NULL)
		return (-1);
	if (data->s_texture == NULL)
		return (-1);
	return (1);
}

int	get_metadata(int fd, t_parse_data *data)
{
	int		err;
	char	*line;

	init_parse_data(data);
	err = 0;
	while (all_set(data) != 1)
	{
		line = get_next_line(fd, &err);
		if (err == -1 || line == NULL)
			break ;
		if (!(west_line(line, data) == 1
				|| east_line(line, data) == 1
				|| north_line(line, data) == 1
				|| south_line(line, data) == 1
				|| celing_line(line, data) == 1
				|| floor_line(line, data) == 1
				|| *line == '\n'))
			return (free(line), get_next_line(-1, &err), -1);
		free(line);
	}
	if (line == NULL)
		return (get_next_line(-1, &err), -1);
	return (1);
}

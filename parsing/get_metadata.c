/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:38:49 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 15:39:08 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static int	all_set(t_parse_data *data)
{
	print_parse_data(data);
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

int		get_metadata(int fd, t_parse_data *data)
{
	int		err;
	char	*line;

	init_parse_data(data);
	err = 0;
	while (all_set(data) != 1)
	{
		line = get_next_line(fd, &err);
		printf("line = %s", line);
		if (err == -1 || line == NULL)
			break ; //error handle
		if (west_line(line, data) == -1 )
			return (free(line), printf("44\n"), -1); //error handle ((this happends only if internal failiure))
		if (east_line(line, data) == -1 )
			return (free(line), printf("46\n"), -1); //error handle ((this happends only if internal failiure))
		if (north_line(line, data) == -1 )
			return (free(line), printf("48\n"), -1); //error handle ((this happends only if internal failiure))
		if (south_line(line, data) == -1 )
			return (free(line), printf("50\n"), -1); //error handle ((this happends only if internal failiure))
		if (celing_line(line, data) == -1 )
			return (free(line), printf("52\n"), -1); //error handle ((this happends only if internal failiure))
		if (floor_line(line, data) == -1 )
			return (free(line), printf("54\n"), -1); //error handle ((this happends only if internal failiure))
	}
	if (line == NULL)
		return (printf("57\n"), -1); //invalid line

	return (1);
}

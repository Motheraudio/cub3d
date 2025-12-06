/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:38:49 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 14:20:18 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int		get_metadata(int fd, t_parse_data *data)
{
	int		err;
	char	*line;

	while (1)
	{
		line = get_next_line(fd, &err);
		if (err == -1)
			break ; //error handle
		if (west_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		if (east_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		if (nort_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		if (south_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		if (celing_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		if (floor_line(line, data) == -1 )
			return (free(line), -1); //error handle ((this happends only if internal failiure))
		free(line);
	}
	if (line == NULL || all_set(data) == -1)
		return (-1); //invalid line
	return (1);
}

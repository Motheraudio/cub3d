/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:59:25 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:43:11 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include "../cleanup/cleanup.h"
#include <fcntl.h>

void	*parse(char *file_name)
{
	t_parse_data	*data;
	int				fd;

	data = malloc(sizeof(t_parse_data));
	if (data == NULL)
		return (NULL);
	init_parse_data(data);
	if (file_sufix(file_name, ".cub") == -1)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (free(data), NULL);
	if (get_metadata(fd, data) == -1)
		return (cleanup_parse(data, NULL), NULL);
	if (validate_map(fd, data) == -1)
		return (cleanup_parse(data, NULL), NULL);
	return (data);
}

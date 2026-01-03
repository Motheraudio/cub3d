/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:13:27 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/11 21:07:12 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
static int	is_correct_size(char *texture)
{
	int	fd;
	char *line;

	fd = open(texture, O_RDONLY);
	if (!fd)
		return (-1);
	line = get_nth_line(fd, 4);
	close(fd);
	if (!line)
		return (-1);
	if (!ft_strncmp(line, "64 64", 5))
		return (free(line), -1);
	free(line);
	return (1);
}

int	check_texture_dimensions(t_parse_data *data)
{
	if (is_correct_size(data->n_texture) == -1)
		return (-1);
	if (is_correct_size(data->s_texture) == -1)
		return (-1);
	if (is_correct_size(data->w_texture) == -1)
		return (-1);
	if (is_correct_size(data->e_texture) == -1)
		return (-1);
	return (1);
}

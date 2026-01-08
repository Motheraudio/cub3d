/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:03:41 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:04:01 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	celing_line(char *line, t_parse_data *data)
{
	char	**tmp;
	int		err;

	err = 0;
	if (ft_strncmp(line, "C ", 2) != 0)
		return (0);
	if (data->celing_set != 0)
		return (-1);
	tmp = ft_split(line + 2, ',');
	if (tmp == NULL)
		return (-1);
	if (tmp[0])
		data->celing.r = colour_atoi(tmp[0], &err);
	if (tmp[0] && tmp[1])
		data->celing.g = colour_atoi(tmp[1], &err);
	if (tmp[0] && tmp[1] && tmp[2])
		data->celing.b = colour_atoi(tmp[2], &err);
	if ((tmp[0] && tmp[1] && tmp[2] && tmp[3] != 0) || err == -1)
		return (free_arr((void ***)&tmp), -1);
	data->celing_set = 1;
	return (free_arr((void ***)&tmp), 1);
}

int	floor_line(char *line, t_parse_data *data)
{
	char	**tmp;
	int		err;

	err = 0;
	if (ft_strncmp(line, "F ", 2) != 0)
		return (0);
	if (data->floor_set != 0)
		return (-1);
	tmp = ft_split(line + 2, ',');
	if (tmp == NULL)
		return (-1);
	if (tmp[0])
		data->floor.r = colour_atoi(tmp[0], &err);
	if (tmp[0] && tmp[1])
		data->floor.g = colour_atoi(tmp[1], &err);
	if (tmp[0] && tmp[1] && tmp[2])
		data->floor.b = colour_atoi(tmp[2], &err);
	if ((tmp[0] && tmp[1] && tmp[2] && tmp[3] != 0) || err == -1)
		return (free_arr((void ***)&tmp), -1);
	data->floor_set = 1;
	return (free_arr((void ***)&tmp), 1);
}

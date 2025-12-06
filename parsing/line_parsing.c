/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:55:55 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 15:37:59 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	west_line(char *line, t_parse_data *data)
{
	char *tmp;

	if (ft_strncmp(line, "WE ", 3) != 0)
		return (0);
	if (data->w_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->w_texture = ft_strtrim(tmp, " \n");
	if(data->w_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	east_line(char *line, t_parse_data *data)
{
	char *tmp;

	if (ft_strncmp(line, "EA ", 3) != 0)
		return (0);
	if (data->e_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->e_texture = ft_strtrim(tmp, " \n");
	if(data->e_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	south_line(char *line, t_parse_data *data)
{
	char *tmp;

	if (ft_strncmp(line, "SO ", 3) != 0)
		return (0);
	if (data->s_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->s_texture = ft_strtrim(tmp, " \n");
	if(data->s_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	north_line(char *line, t_parse_data *data)
{
	char *tmp;

	if (ft_strncmp(line, "NO ", 3) != 0)
		return (0);
	if (data->n_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->n_texture = ft_strtrim(tmp, " \n");
	if(data->n_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	celing_line(char *line, t_parse_data *data)
{
	char	**tmp;
	size_t	i;
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
		data->celing.r = colour_atoi(tmp[1], &err);
	if (tmp[0] && tmp[1] && tmp[2])
		data->celing.r = colour_atoi(tmp[2], &err);
	if ((tmp[0] && tmp[1] && tmp[2] && tmp[3] != 0) || err == -1)
		return (free_arr((void***)&tmp), -1);
	data->celing_set = 1;
	return (free_arr((void ***)&tmp), 1);
}

int	floor_line(char *line, t_parse_data *data)
{
	char	**tmp;
	size_t	i;
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
		data->floor.r = colour_atoi(tmp[1], &err);
	if (tmp[0] && tmp[1] && tmp[2])
		data->floor.r = colour_atoi(tmp[2], &err);
	if ((tmp[0] && tmp[1] && tmp[2] && tmp[3] != 0) || err == -1)
	{
		printf("135 floor line\n");
		printf("err = %i\n", err);
		return (free_arr((void ***)&tmp), -1);
	}
	data->floor_set = 1;
	return (free_arr((void ***)&tmp), 1);
}

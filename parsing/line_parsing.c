/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:55:55 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:03:58 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	west_line(char *line, t_parse_data *data)
{
	char	*tmp;

	if (ft_strncmp(line, "WE ", 3) != 0)
		return (0);
	if (data->w_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->w_texture = ft_strtrim(tmp, " \n");
	if (data->w_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	east_line(char *line, t_parse_data *data)
{
	char	*tmp;

	if (ft_strncmp(line, "EA ", 3) != 0)
		return (0);
	if (data->e_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->e_texture = ft_strtrim(tmp, " \n");
	if (data->e_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	south_line(char *line, t_parse_data *data)
{
	char	*tmp;

	if (ft_strncmp(line, "SO ", 3) != 0)
		return (0);
	if (data->s_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->s_texture = ft_strtrim(tmp, " \n");
	if (data->s_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

int	north_line(char *line, t_parse_data *data)
{
	char	*tmp;

	if (ft_strncmp(line, "NO ", 3) != 0)
		return (0);
	if (data->n_texture != NULL)
		return (-1);
	tmp = ft_substr(line, 2, ft_strlen(line));
	if (tmp == NULL)
		return (-1);
	data->n_texture = ft_strtrim(tmp, " \n");
	if (data->n_texture == NULL)
		return (free(tmp), -1);
	free(tmp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:00:51 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:41:49 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	file_sufix(char *file_name, char *sufix)
{
	ssize_t	i;
	ssize_t	j;

	i = ft_strlen(file_name);
	j = ft_strlen(sufix);
	while (j >= 0 && i >= 0)
	{
		if (!(file_name[i] == sufix[j]))
			return (-1);
		i --;
		j --;
	}
	if (i == -1)
		return (-1);
	return (1);
}

void	init_parse_data(t_parse_data *data)
{
	data->e_texture = NULL;
	data->w_texture = NULL;
	data->n_texture = NULL;
	data->s_texture = NULL;
	data->floor_set = 0;
	data->celing_set = 0;
	data->floor.r = 0;
	data->floor.g = 0;
	data->floor.b = 0;
	data->celing.r = 0;
	data->celing.g = 0;
	data->celing.b = 0;
	data->tall = 0;
	data->wide = 0;
	data->emap = NULL;
	data->str_arr_map = NULL;
	data->orientation = UNI;
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
}

void	print_parse_data(t_parse_data *data)
{
	printf("data->n_texture = \"%s\"\n", data->n_texture);
	printf("data->s_texture = \"%s\"\n", data->s_texture);
	printf("data->w_texture = \"%s\"\n", data->w_texture);
	printf("data->e_texture = \"%s\"\n", data->e_texture);
	printf("data->celing_set = %i\n", data->celing_set);
	printf("	data->celing.r= %u\n", data->celing.r);
	printf("	data->celing.g= %u\n", data->celing.g);
	printf("	data->celing.b= %u\n", data->celing.b);
	printf("data->floor_set = %i\n", data->floor_set);
	printf("	data->floor.r= %u\n", data->floor.r);
	printf("	data->floor.g= %u\n", data->floor.g);
	printf("	data->floor.b= %u\n", data->floor.b);
	print_emap(data);
}

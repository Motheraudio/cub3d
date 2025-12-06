/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:00:51 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 13:49:50 by mchoma           ###   ########.fr       */
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
}

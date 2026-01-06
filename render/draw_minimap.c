/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:03:38 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 15:43:38 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_minimap(t_2d *minimap, t_parse_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < data->tall - 1)
	{
		j = 1;
		while (j < data->wide - 1)
		{
			if (data->emap[i][j] == WALL)
				draw_wall(minimap, (j - 1) * WALL_LEN, (i - 1) * WALL_LEN);
			if (data->emap[i][j] == FLOOR || data->emap[i][j] == PLAYER)
				draw_floor(minimap, (j - 1) * WALL_LEN, (i - 1) * WALL_LEN);
			j ++;
		}
		i ++;
	}
}

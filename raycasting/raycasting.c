/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:46:23 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/07 23:07:40 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_test/render.h"
#include "raycasting.h"

void	casting_ray(t_2d *minimap, t_line *line, t_raycast *res)
{
	t_algo	algo;

	res->distance = 0;
	initline(&algo, line);
	while (1)
	{
		res->distance ++;
		res->colour = pixel_color(minimap, line->x1, line->y1);
		if (res->colour != FLOOR_COLOUR)
		{
			res->x_hit = line->x1;
			res->y_hit = line->y1;
			return ;
		}
		algo.p2 = 2 * algo.p;
		if (algo.p2 >= algo.deltay)
		{
			algo.p += algo.deltay;
			line->x1 += algo.dirx;
		}
		if (algo.p2 <= algo.deltax)
		{
			algo.p += algo.deltax;
			line->y1 += algo.diry;
		}
	}
}


void	raycasting(t_raycast *arr, t_player *player)
{
	t_line	line;
	size_t	i;
	
	i = 0;
	while (i < RAYCAST_ARR)
	{
		line.x1 = player->x;
		line.y1 = player->y;
		line.x2 = player->x + RAY_LEN * cos(player->radian - 0.26179 + i * 0.523598 / RAYCAST_ARR);
		line.y2 = player->y + RAY_LEN * sin(player->radian - 0.26179 + i * 0.523598 / RAYCAST_ARR);
		casting_ray(player->minimap, &line, arr + i);
		i ++;
	}
}

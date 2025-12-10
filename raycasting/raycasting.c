/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:46:23 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/08 22:08:38 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_test/render.h"
#include "raycasting.h"
# include <math.h>

void	casting_ray(t_2d *image, t_line *line, t_raycast *res)
{
	t_algo	algo;

	res->distance = 0;
	initline(&algo, line);
	while (1)
	{
		res->distance ++;
		res->colour = pixel_color(image, line->x1, line->y1);
		// printf("%X == res->colour2\n", res->colour);
		if (!(res->colour == FLOOR_COLOUR || res->colour == RAY_COLOUR)) // remove second condition
		{
			res->x_hit = line->x1;
			res->y_hit = line->y1;
			return ;
		}
		my_mlx_pixel_put(image, line->x1, line->y1, RAY_COLOUR);
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

void	casting_ray_test(t_2d *image, t_line *line, t_raycast *res)
{
	t_algo	algo;

	res->distance = 0;
	res->colour = FLOOR_COLOUR;
	initline(&algo, line);
	while (1)
	{
		res->distance ++;
		my_mlx_pixel_put(image, line->x1, line->y1, BLUE);
		res->colour = pixel_color(image, line->x1, line->y1);
		if (!((res->colour == (~FLOOR_COLOUR) >> 8) || res->colour == BLUE))
		{
			printf("%X == res->colour\n", res->colour);
			// printf("%X == FLOOR_COLOUR\n", (unsigned int)(~FLOOR_COLOUR) >> 8);
			printf("%X == BLUE\n", BLUE);
			printf("%lu\n", res->distance);
			res->x_hit = line->x1;
			res->y_hit = line->y1;
			return ;
		}
		my_mlx_pixel_put(image, line->x1, line->y1, BLUE);
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



void	raycasting(t_raycast arr[], t_player *player, t_2d *minimap)
{
	t_line	line;
	size_t	i;
	
	i = 0;
	while (i < RAYCAST_ARR)
	{
		printf("i == %lu\n", i);
		line.x1 = player->x;
		line.y1 = player->y;
		line.x2 = player->x + RAY_LEN * cos(player->radian - 0.26179 + M_PI_2 + (i * 0.523598 / RAYCAST_ARR));
		line.y2 = player->y + RAY_LEN * sin(player->radian - 0.26179 + M_PI_2 + (i * 0.523598 / RAYCAST_ARR));
		casting_ray(minimap, &line, arr + i);
		// casting_ray_test(minimap, &line, arr + i); //for testing purposes
		i ++;
	}
}

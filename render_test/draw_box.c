/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:51:18 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/07 22:13:43 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_line_scale(t_2d *minimap, t_line *line)
{
	t_algo	algo;
	unsigned int	i;
	unsigned int	mask;

	i = 0;
	mask = 0x01;
	initline(&algo, line);
	while (1)
	{
		// if (checksize(line->x1, line->y1) == 0)
			// break ;
		my_mlx_pixel_put(minimap, line->x1, line->y1, line->colour + i);
		algo.p2 = 2 * algo.p;
		if (algo.p2 >= algo.deltay)
		{
			if (line->x1 == line->x2)
				break ;
			algo.p += algo.deltay;
			line->x1 += algo.dirx;
		}
		if (algo.p2 <= algo.deltax)
		{
			if (line->y1 == line->y2)
				break ;
			algo.p += algo.deltax;
			line->y1 += algo.diry;
		}
		i += mask;
	}
}

void	draw_wall(t_2d *minimap, int x, int y) {
	t_line	line;
	size_t	i;

	i = 0;
	while (i < WALL_LEN)
	{
		line.x1 = x + 1;
		line.x2 = x + WALL_LEN;
		line.y1 = y + i + 1;
		line.y2 = y + i + 1;
		line.colour = VOID_COLOUR;
		draw_line(minimap, &line);
		i ++;
	}

	line.x1 = x;
	line.y1 = y;
	line.x2 = x + WALL_LEN;
	line.y2 = y;
	line.colour = SOUTH_C;
	draw_line_scale(minimap, &line);

	line.x1 = x;
	line.y1 = y;
	line.x2 = x;
	line.y2 = y + WALL_LEN;
	line.colour = WEST_C;
	draw_line_scale(minimap, &line);

	line.x1 = x + WALL_LEN;
	line.y1 = y;
	line.x2 = x + WALL_LEN;
	line.y2 = y + WALL_LEN;
	line.colour = EAST_C;
	draw_line_scale(minimap, &line);

	line.x1 = x;
	line.y1 = y + WALL_LEN;
	line.x2 = x + WALL_LEN;
	line.y2 = y + WALL_LEN;
	line.colour = NORTH_C;
	draw_line_scale(minimap, &line);
}

void	draw_floor(t_2d *minimap, int x, int y)
{
	t_line	line;
	size_t	i;

	i = 0;
	x ++;
	y ++;
	while (i < WALL_LEN)
	{
		line.x1 = x;
		line.x2 = x + WALL_LEN;
		line.y1 = y + i;
		line.y2 = y + i;
		line.colour = FLOOR_COLOUR;
		draw_line(minimap, &line);
		i ++;
	}
}


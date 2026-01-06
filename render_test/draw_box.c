/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:51:18 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 15:43:15 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_east_north(t_2d *minimap, int x, int y, t_line *line)
{
	line->x1 = x + WALL_LEN;
	line->y1 = y;
	line->x2 = x + WALL_LEN;
	line->y2 = y + WALL_LEN;
	line->colour = EAST_C;
	draw_line_scale(minimap, line);
	line->x1 = x;
	line->y1 = y + WALL_LEN;
	line->x2 = x + WALL_LEN;
	line->y2 = y + WALL_LEN;
	line->colour = NORTH_C;
	draw_line_scale(minimap, line);
}

static void	draw_south_west(t_2d *minimap, int x, int y, t_line *line)
{
	line->x1 = x;
	line->y1 = y;
	line->x2 = x + WALL_LEN;
	line->y2 = y;
	line->colour = SOUTH_C;
	draw_line_scale(minimap, line);
	line->x1 = x;
	line->y1 = y;
	line->x2 = x;
	line->y2 = y + WALL_LEN;
	line->colour = WEST_C;
	draw_line_scale(minimap, line);
}

void	draw_wall(t_2d *minimap, int x, int y)
{
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
	draw_south_west(minimap, x, y, &line);
	draw_east_north(minimap, x, y, &line);
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

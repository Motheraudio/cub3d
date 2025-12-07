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

void	draw_wall(t_2d *minimap, int x, int y) {
	t_line	line;

	line.x1 = x;
	line.y1 = y;
	line.x2 = x + WALL_LEN;
	line.y2 = y;
	line.colour = RED;
	draw_line(minimap, &line);

	line.x1 = x;
	line.y1 = y;
	line.x2 = x;
	line.y2 = y + WALL_LEN;
	line.colour = MAGENTA;
	draw_line(minimap, &line);

	line.x1 = x + WALL_LEN;
	line.y1 = y;
	line.x2 = x + WALL_LEN;
	line.y2 = y + WALL_LEN;
	line.colour = BLUE;
	draw_line(minimap, &line);

	line.x1 = x;
	line.y1 = y + WALL_LEN;
	line.x2 = x + WALL_LEN;
	line.y2 = y + WALL_LEN;
	line.colour = GREEN;
	draw_line(minimap, &line);
}

void	draw_floor(t_2d *minimap, int x, int y)
{
	t_line	line;
	size_t	i;

	i = 0;
	x ++;
	y ++;
	while (i < WALL_LEN - 1)
	{
		line.x1 = x;
		line.x2 = x + WALL_LEN - 1;
		line.y1 = y + i;
		line.y2 = y + i;
		line.colour = FLOOR_COLOUR;
		draw_line(minimap, &line);
		i ++;
	}
}


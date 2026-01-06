/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:00:39 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 15:47:18 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "render.h"

void	initline(t_algo *algo, t_line *line)
{
	algo->deltax = abs(line->x2 - line->x1);
	algo->deltay = -abs(line->y2 - line->y1);
	algo->p = algo->deltay + algo->deltax;
	algo->dirx = calcdir(line->x1, line->x2);
	algo->diry = calcdir(line->y1, line->y2);
}
/* 0x01 represents the mask used for the color coding*/

void	draw_line_scale(t_2d *minimap, t_line *line)
{
	t_algo			algo;
	unsigned int	i;

	i = 0;
	initline(&algo, line);
	while (1)
	{
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
		i += 0x01;
	}
}

void	draw_line(t_2d *minimap, t_line *line)
{
	t_algo	algo;

	initline(&algo, line);
	while (1)
	{
		my_mlx_pixel_put(minimap, line->x1, line->y1, line->colour);
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
	}
}

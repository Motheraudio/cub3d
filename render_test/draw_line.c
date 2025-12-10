/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:00:39 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/07 22:53:17 by mchoma           ###   ########.fr       */
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

void	draw_line(t_2d *minimap, t_line *line)
{
	t_algo	algo;

	initline(&algo, line);
	while (1)
	{
		// if (checksize(line->x1, line->y1) == 0)
			// break ;
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




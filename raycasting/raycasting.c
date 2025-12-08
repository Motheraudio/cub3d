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

unsigned int	casting_ray(t_2d *minimap, t_line *line)
{
	t_algo			algo;
	size_t			i;
	unsigned int	colour;

	i = 0;
	initline(&algo, line);
	while (1)
	{
		i ++;
		colour = pixel_color(minimap, line->x1, line->y1);
		if (colour != FLOOR_COLOUR)
			return (colour);
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


void	raycasting(t_raycast *arr, int x, int i, float radian, )
{

}

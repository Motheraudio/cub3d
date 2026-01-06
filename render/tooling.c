/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:36:26 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/06 15:54:25 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

unsigned int	pixel_color(t_2d *data, int x, int y)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length)
			+ (x * (data->bits_per_pixel / 8)));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_2d *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length)
			+ (x * (data->bits_per_pixel / 8)));
	*(unsigned int *)dst = (unsigned int)color;
}

int	calcdir(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	else
		return (-1);
}

int	checksize(int x1, int y1)
{
	if (x1 > WIDTH - 1 || x1 < 0
		|| y1 < 0 || y1 > HEIGHT - 1)
		return (0);
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:08:27 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 17:09:59 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	put_floor(t_bundle *bundle, size_t *i)
{
	unsigned int	color;
	size_t			j;

	j = 0;
	color = (bundle->data->celing.r << 16)
		+ (bundle->data->celing.g << 8) + bundle->data->celing.b;
	while (*i < HEIGHT / 2)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(bundle->view, j, *i, color);
			j++;
		}
		j = 0;
		(*i)++;
	}
}

void	put_ceiling(t_bundle *bundle, size_t *i)
{
	unsigned int	color;
	size_t			j;

	j = 0;
	color = (unsigned int)((unsigned int)(bundle->data->floor.r << 16)
			+ (unsigned int)(bundle->data->floor.g << 8)
			+ (unsigned int)bundle->data->floor.b);
	while (*i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(bundle->view, j, *i, color);
			j++;
		}
		j = 0;
		(*i)++;
	}
}

void	put_floor_and_ceiling(t_bundle *bundle)
{
	size_t	i;

	i = 0;
	put_floor(bundle, &i);
	put_ceiling(bundle, &i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:57:02 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 17:10:41 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

void	clear_3d_image(t_bundle *bundle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(bundle->view, j, i, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
}

int	get_texture_x_mirrored(t_raycast *ray, int wall_hit_x, int wall_hit_y)
{
	int				tex_x;
	double			hit_pos;
	unsigned int	orientation;

	orientation = get_orientation(ray->colour);
	if (orientation == NORTH_C || orientation == SOUTH_C)
		hit_pos = (double)wall_hit_x;
	else
		hit_pos = (double)wall_hit_y;
	hit_pos = hit_pos - floor(hit_pos / WALL_LEN) * WALL_LEN;
	tex_x = (int)((hit_pos / (double)WALL_LEN) * TILESIZE);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TILESIZE)
		tex_x = TILESIZE - 1;
	if (orientation == EAST_C || orientation == SOUTH_C)
		tex_x = 64 - tex_x;
	return (tex_x);
}

int	get_texture_x(t_raycast *ray, int wall_hit_x, int wall_hit_y)
{
	int				tex_x;
	double			hit_pos;
	unsigned int	orientation;

	orientation = get_orientation(ray->colour);
	if (orientation == NORTH_C || orientation == SOUTH_C)
		hit_pos = (double)wall_hit_x;
	else
		hit_pos = (double)wall_hit_y;
	hit_pos = hit_pos - floor(hit_pos / WALL_LEN) * WALL_LEN;
	tex_x = (int)((hit_pos / (double)WALL_LEN) * TILESIZE);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TILESIZE)
		tex_x = TILESIZE - 1;
	return (tex_x);
}

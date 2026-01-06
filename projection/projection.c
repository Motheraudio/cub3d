/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:58:49 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 17:03:56 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projection.h"

static void	init_column(t_raycast *ray, t_column *column, int wall_height)
{
	column->start_y = (HEIGHT / 2) - (wall_height / 2);
	column->end_y = (HEIGHT / 2) + (wall_height / 2);
	column->tex_x = get_texture_x(ray, ray->x_hit, ray->y_hit);
	column->orientation = get_orientation(ray->colour);
	column->tex_index = get_texture_index(column->orientation);
	column->step = (double)TILESIZE / (double)wall_height;
	column->tex_pos = 0;
}

static void	draw_wall_column(t_bundle *bundle, int x, t_raycast *ray,
							int wall_height)
{
	t_column	column;

	init_column(ray, &column, wall_height);
	if (column.start_y < 0)
	{
		column.tex_pos = (-column.start_y) * column.step;
		column.start_y = 0;
	}
	if (column.end_y >= HEIGHT)
		column.end_y = HEIGHT - 1;
	column.y = column.start_y;
	while (column.y <= column.end_y)
	{
		column.tex_y = (int)column.tex_pos;
		if (column.tex_y < 0)
			column.tex_y = 0;
		if (column.tex_y >= TILESIZE)
			column.tex_y = TILESIZE - 1;
		column.color = pixel_color(bundle->data->textures[column.tex_index],
				column.tex_x, column.tex_y);
		my_mlx_pixel_put(bundle->view, x, column.y, column.color);
		column.tex_pos += column.step;
		column.y++;
	}
}

static void	draw_slice(t_bundle *bundle, t_draw *draw, t_raycast rays[], int i)
{
	while (draw->pixel_offset < draw->pixels_per_ray)
	{
		draw->screen_x = (i * draw->pixels_per_ray) + draw->pixel_offset;
		if (draw->screen_x < WIDTH)
			draw_wall_column(bundle, draw->screen_x, &rays[i],
				draw->wall_height);
		draw->pixel_offset++;
	}
}

//fov value is 30 deg in radians.

static void	set_draw_params(t_draw *draw)
{
	draw->pixels_per_ray = WIDTH / RAYCAST_ARR;
	if (draw->pixels_per_ray == 0)
		draw->pixels_per_ray = 1;
	draw->fov = 0.523598;
}

void	draw_3d(t_raycast rays[], t_bundle *bundle)
{
	t_draw	draw;
	int		i;

	put_floor_and_ceiling(bundle);
	set_draw_params(&draw);
	i = 0;
	while (i < RAYCAST_ARR)
	{
		draw.ray_angle = (bundle->player->radian - draw.fov / 3.0)
			+ (i * draw.fov / RAYCAST_ARR);
		draw.angle_diff = fabs(draw.ray_angle - bundle->player->radian);
		if (draw.angle_diff > M_PI * 2)
			draw.angle_diff -= (M_PI * 2);
		else if (draw.angle_diff < 0)
			draw.angle_diff += (M_PI * 2);
		draw.corrected_distance = (double)rays[i].distance
			* cos(draw.angle_diff);
		if (draw.corrected_distance < 0.0001f)
			draw.corrected_distance = 0.0001f;
		draw.wall_height = TILESIZE * HEIGHT / draw.corrected_distance;
		draw.pixel_offset = 0;
		draw_slice(bundle, &draw, rays, i);
		i++;
	}
}

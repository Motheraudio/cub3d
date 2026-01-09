/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:46:29 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 17:08:11 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H
# include "../render/render.h"
# include "../raycasting/raycasting.h"
# include "../parsing/parsing.h"

typedef struct s_column
{
	int				y;
	int				tex_x;
	int				tex_y;
	int				start_y;
	int				end_y;
	int				tex_index;
	double			step;
	double			tex_pos;
	unsigned int	color;
	unsigned int	orientation;
}	t_column;
typedef struct s_draw
{
	int		wall_height;
	double	corrected_distance;
	double	ray_angle;
	double	angle_diff;
	int		screen_x;
	int		pixels_per_ray;
	int		pixel_offset;
	double	fov;
}	t_draw;

void	draw_3d(t_raycast rays[], t_bundle *bundle);
void	put_floor_and_ceiling(t_bundle *bundle);
int		get_texture_x(t_raycast *ray, int wall_hit_x, int wall_hit_y);
void	clear_3d_image(t_bundle *bundle);
int		get_texture_x_mirrored(t_raycast *ray, int wall_hit_x, int wall_hit_y);
#endif

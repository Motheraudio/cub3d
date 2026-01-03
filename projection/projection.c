#include "projection.h"

void	put_floor_and_ceiling(t_bundle *bundle)
{
	size_t i;
	size_t	j;
	unsigned int	color;
	i = 0;
	j = 0;
	color = (bundle->data->celing.r << 8) + (bundle->data->celing.g << 8) + bundle->data->celing.b;
	while (i < HEIGHT / 2)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(bundle->view, j, i, color);
			j++;
		}
		j = 0;
		i++;
	}

	color = (unsigned int) ((unsigned int)(bundle->data->floor.r << 8) + (unsigned int)(bundle->data->floor.g << 8) + (unsigned int)bundle->data->floor.b);
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(bundle->view, j, i, color);
			j++;
		}
		j = 0;
		i++;
	}
		
}

void	clear_3d_image(t_bundle *bundle)
{
	size_t i;
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
static int	get_texture_x(t_raycast *ray, int wall_hit_x, int wall_hit_y)
{
	int tex_x;
	double hit_pos;
	unsigned int orientation;
	
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
		
	return tex_x;
}

static void	draw_wall_column(t_bundle *bundle, int x, t_raycast *ray, int wall_height)
{
	int			y;
	int			tex_x;
	int			tex_y;
	int			start_y;
	int			end_y;
	int			tex_index;
	double		step;
	double		tex_pos;
	unsigned int color;
	unsigned int orientation;

	start_y = (HEIGHT / 2) - (wall_height / 2);
	end_y = (HEIGHT / 2) + (wall_height / 2);
	tex_x = get_texture_x(ray, ray->x_hit, ray->y_hit);
	orientation = get_orientation(ray->colour);
	tex_index = get_texture_index(orientation);
	step = (double)TILESIZE / (double)wall_height;
	tex_pos = 0;
	if (start_y < 0)
	{
		tex_pos = (-start_y) * step;
		start_y = 0;
	}
	if (end_y >= HEIGHT)
		end_y = HEIGHT - 1;
	y = start_y;
	while (y <= end_y)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= TILESIZE)
			tex_y = TILESIZE - 1;
		color = pixel_color(bundle->data->textures[tex_index], tex_x, tex_y);
		my_mlx_pixel_put(bundle->view, x, y, color);
		tex_pos += step;
		y++;
	}
}

void	draw_3d(t_raycast rays[], t_bundle *bundle)
{
	int		i;
	int		wall_height;
	double	corrected_distance;
	double	ray_angle;
	double	angle_diff;
	int		screen_x;
	int		pixels_per_ray;
	int		pixel_offset;
	double	fov;
	
	put_floor_and_ceiling(bundle);
	pixels_per_ray = WIDTH / RAYCAST_ARR;
	if (pixels_per_ray == 0)
		pixels_per_ray = 1;
	fov = 0.523598; // 30 degrees in radians
	i = 0;
	while (i < RAYCAST_ARR)
	{
		ray_angle = (bundle->player->radian - fov / 2.0) + (i * fov / RAYCAST_ARR);
		angle_diff = ray_angle - bundle->player->radian;
		corrected_distance = (double)rays[i].distance * cos(angle_diff);
		if (corrected_distance < 0.1)
			corrected_distance = 0.1;
		wall_height = (int)((double)(WALL_LEN * TILESIZE * HEIGHT) / (corrected_distance * TILESIZE));
		pixel_offset = 0;
		while (pixel_offset < pixels_per_ray)
		{
			screen_x = (i * pixels_per_ray) + pixel_offset;
			if (screen_x < WIDTH)
				draw_wall_column(bundle, screen_x, &rays[i], wall_height);
			pixel_offset++;
		}
		
		i++;
	}
}

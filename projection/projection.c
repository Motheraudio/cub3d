#include "projection.h"

void	put_floor_and_ceiling(t_bundle *bundle)
{
	size_t i;
	size_t	j;
	unsigned int	color;
	i = 0;
	j = 0;
	printf("%X = R\n", bundle->data->celing.r);
	printf("%X = G\n", bundle->data->celing.g);
	printf("%X = B\n", bundle->data->celing.b);
	color = (bundle->data->celing.r << 8) + (bundle->data->celing.g << 8) + bundle->data->celing.b;
	printf("%X = COLOR\n", color);
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
void	draw_3d(t_raycast rays[], t_bundle *bundle)
{
	int	i;
	double	line_height;
	int	draw_start;
	int	draw_end;
	int	x;
	int	col;
	int y;

	col = 0xAAAAAA;
	i = 0;
	clear_3d_image(bundle);
	put_floor_and_ceiling(bundle);
	while(i < RAYCAST_ARR)
	{
		if(rays[i].distance <= 0)
			continue;
		line_height = ((double)HEIGHT / (double)rays[i].distance);
		draw_start = -line_height / 2 + (double)HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + (double)HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		x = i * (WIDTH / RAYCAST_ARR);
		y = draw_start;
		while (y < draw_end)
		{
			my_mlx_pixel_put(bundle->view, x, y, col);
			y++;
		}
		i++;
	}
	
}
